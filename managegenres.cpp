#include "managegenres.h"
#include "ui_managegenres.h"
#include "mainwindow.h"
#include <CustomMessageBox.h>
#include <QDebug>


ManageGenres::ManageGenres(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManageGenres)
{
    ui->setupUi(this);
    this->setWindowTitle("Manage Genres");
    populateTableWithGenres();
}

ManageGenres::~ManageGenres()
{
    delete ui;
}

void ManageGenres::on_addButton_clicked()
{
    // Get genre details from input fields
    QString ID = ui->bookID->text();
    QString genreName = ui->genre->text();

    // Check if any input field is empty
    if (ID.isEmpty() || genreName.isEmpty()) {
        CustomMessageBox::warning(this, "Empty Fields", "Both ID and Genre fields must be filled.");
        return;
    }

    for (const Genre& existingGenre : genres) {
        if (existingGenre.id == ID) {
            CustomMessageBox::warning(this, "Duplicate ID", "A genre with the same ID already exists.");
            return;
        }
    }
    // Create a new genre object
    // Genre newGenre{id, genreName};
    Genre newGenre;
    newGenre.id = ID;
    newGenre.name = genreName;

    // Add the new genre to the vector
    genres.push_back(newGenre);

    // Populate the table with genres after adding a new genre
    populateTableWithGenres();

    // Clear the input fields
    ui->bookID->clear();
    ui->genre->clear();

}


void ManageGenres::populateTableWithGenres() {
    // Clear existing data in the table
    // ui->genreTableWidget->clearContents();
    ui->genreTableWidget->setRowCount(genres.size()); // Set the number of rows in the table

    // Populate the table with genres
    for (size_t i = 0; i < genres.size(); ++i) {
        const Genre& genre = genres[i]; // Use a reference to avoid unnecessary copying

        // Create items for each column
        QTableWidgetItem *idItem = new QTableWidgetItem(genre.id);
        QTableWidgetItem *nameItem = new QTableWidgetItem(genre.name);

        // Set the items in the table
        ui->genreTableWidget->setItem(i, 0, idItem); // Column 0 for ID
        ui->genreTableWidget->setItem(i, 1, nameItem); // Column 1 for Name
    }
}


void ManageGenres::on_editButton_clicked()
{
    QModelIndexList selectedRows = ui->genreTableWidget->selectionModel()->selectedRows();

    // Check if a row is selected
    if (!selectedRows.isEmpty())
    {
        // Get the first selected row index
        QModelIndex selectedIndex = selectedRows.first();

        // Get the genre ID and name from the selected row
        QString selectedID = ui->genreTableWidget->model()->data(ui->genreTableWidget->model()->index(selectedIndex.row(), 0)).toString();
        QString selectedName = ui->genreTableWidget->model()->data(ui->genreTableWidget->model()->index(selectedIndex.row(), 1)).toString();

        // Get the edited ID and name from the line edit fields
        QString editedID = ui->bookID->text();
        QString editedName = ui->genre->text();

        // Check if the edited ID is the same as any existing ID in the table
        for (const Genre& existingGenre : genres) {
            if (existingGenre.id == editedID && existingGenre.id != selectedID) {
                CustomMessageBox::warning(this, "Duplicate ID", "An entry with the same ID already exists.");
                return;
            }
        }

        // Update the information in the genres vector
        genres[selectedIndex.row()].id = editedID;
        genres[selectedIndex.row()].name = editedName;

        // Update the table with the edited information
        ui->genreTableWidget->model()->setData(ui->genreTableWidget->model()->index(selectedIndex.row(), 0), editedID);
        ui->genreTableWidget->model()->setData(ui->genreTableWidget->model()->index(selectedIndex.row(), 1), editedName);
    }
    else
    {
        // If no row is selected, display a warning message
        CustomMessageBox::warning(this, "No Row Selected", "Please select a row to edit.");
        return;
    }
}

void ManageGenres::on_deleteButton_clicked()
{
    QModelIndexList selectedRows = ui->genreTableWidget->selectionModel()->selectedRows();

    // Check if a row is selected
    if (!selectedRows.isEmpty())
    {
        // Get the first selected row index
        QModelIndex selectedIndex = selectedRows.first();

        // Remove the selected row from the genres vector
        genres.erase(genres.begin() + selectedIndex.row());

        // Remove the selected row from the table
        ui->genreTableWidget->removeRow(selectedIndex.row());
    }
    else
    {
        // If no row is selected, display a warning message
        CustomMessageBox::warning(this, "No Row Selected", "Please select a row to delete.");
        return;
    }
}

void ManageGenres::on_backButton_clicked()
{
    this->hide();
    MainWindow mainwindow;
    mainwindow.show();
}

QVector<Genre>& ManageGenres::getAllGenres() const {
    return genres;
}

QVector<Genre> ManageGenres::genres;

