#include "manageauthors.h"
#include "ui_manageauthors.h"

#include <QMessageBox>

ManageAuthors::ManageAuthors(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManageAuthors)
{
    ui->setupUi(this);
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
    ui->authorTableWidget->clearContents();
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

}


void ManageAuthors::on_deleteButton_clicked()
{

}

QVector<Author> ManageAuthors::authors;
