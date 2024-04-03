#include "manageauthors.h"
#include "ui_manageauthors.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "info.h"

ManageAuthors::ManageAuthors(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManageAuthors)
{
    ui->setupUi(this);

    // Load the data into the authors vector
    loadDataFromInfo();

    // Populate the table with authors
    populateTableWithAuthors();
}

ManageAuthors::~ManageAuthors()
{
    delete ui;
}

void ManageAuthors::on_addButton_clicked()
{
    QString id = ui->id->text();
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString expertise = ui->expertise->text();
    QString about = ui->about->toPlainText();

    // Check if any field is empty
    if (id.isEmpty() || firstName.isEmpty() || lastName.isEmpty() || expertise.isEmpty() || about.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "All fields must be filled.");
        return;
    }

    // Check if the ID already exists
    for (const Author& author : authors) {
        if (author.id == id) {
            QMessageBox::warning(this, "Duplicate ID", "An author with the same ID already exists.");
            return;
        }
    }

    // Create a new author object
    Author newAuthor{id, firstName, lastName, expertise, about};

    // Add the new author to the vector
    authors.push_back(newAuthor);

    Info info;
    QVector<Genre> emptyGenres;
    QVector<Users> emptyLibrarians;
    QVector<Book> emptyBooks;
    QVector<Member> emptyMembers;
    info.saveData(emptyLibrarians, authors, emptyGenres, emptyBooks, emptyMembers);

    // Populate the table with authors after adding a new author
    populateTableWithAuthors();

    // Clear the input fields
    ui->id->clear();
    ui->firstName->clear();
    ui->lastName->clear();
    ui->expertise->clear();
    ui->about->clear();
}

void ManageAuthors::populateTableWithAuthors() {
    // Clear existing data in the table
    // ui->authorTableWidget->clearContents();
    ui->authorTableWidget->setRowCount(authors.size()); // Set the number of rows in the table

    // Populate the table with authors
    for (int i = 0; i < authors.size(); ++i) {
        const Author& author = authors[i]; // Use a reference to avoid unnecessary copying

        // Create items for each column
        QTableWidgetItem *idItem = new QTableWidgetItem(author.id);
        QTableWidgetItem *firstNameItem = new QTableWidgetItem(author.firstName);
        QTableWidgetItem *lastNameItem = new QTableWidgetItem(author.lastName);
        QTableWidgetItem *expertiseItem = new QTableWidgetItem(author.expertise);
        QTableWidgetItem *aboutItem = new QTableWidgetItem(author.about);

        // Set the items in the table
        ui->authorTableWidget->setItem(i, 0, idItem); // Column 0 for ID
        ui->authorTableWidget->setItem(i, 1, firstNameItem); // Column 1 for First Name
        ui->authorTableWidget->setItem(i, 2, lastNameItem); // Column 2 for Last Name
        ui->authorTableWidget->setItem(i, 3, expertiseItem); // Column 3 for Expertise
        ui->authorTableWidget->setItem(i, 4, aboutItem); // Column 4 for About

    }
}


void ManageAuthors::on_editButton_clicked()
{
    QModelIndexList selectedRows = ui->authorTableWidget->selectionModel()->selectedRows();

    // Check if a row is selected
    if (!selectedRows.isEmpty())
    {
        // Get the first selected row index
        QModelIndex selectedIndex = selectedRows.first();
        int selectedRow = selectedIndex.row();

        // Get the current author's information
        QString editedID = ui->id->text();
        QString editedFirstName = ui->firstName->text();
        QString editedLastName = ui->lastName->text();
        QString editedExpertise = ui->expertise->text();
        QString editedAbout = ui->about->toPlainText();

        // Update the item widgets in the table with the edited information
        ui->authorTableWidget->item(selectedRow, 0)->setText(editedID);
        ui->authorTableWidget->item(selectedRow, 1)->setText(editedFirstName);
        ui->authorTableWidget->item(selectedRow, 2)->setText(editedLastName);
        ui->authorTableWidget->item(selectedRow, 3)->setText(editedExpertise);
        ui->authorTableWidget->item(selectedRow, 4)->setText(editedAbout);

        // Update the authors vector with the edited information
        authors[selectedRow].id = editedID;
        authors[selectedRow].firstName = editedFirstName;
        authors[selectedRow].lastName = editedLastName;
        authors[selectedRow].expertise = editedExpertise;
        authors[selectedRow].about = editedAbout;

        // Save the updated data
        Info info;
        QVector<Genre> emptyGenres;
        QVector<Users> emptyLibrarians;
        QVector<Book> emptyBooks;
        QVector<Member> emptyMembers;
        info.saveData(emptyLibrarians, authors, emptyGenres, emptyBooks, emptyMembers);
    }
    else
    {
        // If no row is selected, display a warning message
        QMessageBox::warning(this, "No Row Selected", "Please select a row to edit.");
    }
}

void ManageAuthors::on_deleteButton_clicked()
{
    QModelIndexList selectedRows = ui->authorTableWidget->selectionModel()->selectedRows();

    // Check if a row is selected
    if (!selectedRows.isEmpty())
    {
        // Get the first selected row index
        QModelIndex selectedIndex = selectedRows.first();
        int selectedRow = selectedIndex.row();

        // Remove the author at the selected row index
        authors.erase(authors.begin() + selectedRow);

        // Update the table after deleting
        populateTableWithAuthors();

        Info info;
        QVector<Genre> emptyGenres;
        QVector<Users> emptyLibrarians;
        QVector<Book> emptyBooks;
        QVector<Member> emptyMembers;
        info.saveData(emptyLibrarians, authors, emptyGenres, emptyBooks, emptyMembers);
    }
    else
    {
        // If no row is selected, display a warning message
        QMessageBox::warning(this, "No Row Selected", "Please select a row to delete.");
    }
}


QVector<Author>& ManageAuthors::getAllAuthors() const {
    return authors;
}


void ManageAuthors::on_backButton_clicked()
{
    this->hide();
    MainWindow mainwindow;
    mainwindow.show();
}

void ManageAuthors::loadDataFromInfo() {
    Info info; // Create an instance of the Info class
    QVector<Genre> emptyGenres; // Create an empty QVector<Genre>
    QVector<Users> emptyLibrarians;
    QVector<Book> emptyBooks;
    QVector<Member> emptyMembers;
    // Load the data into the authors vector
    info.loadData(emptyLibrarians, authors, emptyGenres, emptyBooks, emptyMembers);
    populateTableWithAuthors();
}

QVector<Author> ManageAuthors::authors;

