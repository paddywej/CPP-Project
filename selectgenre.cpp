#include "selectgenre.h"
#include "ui_selectgenre.h"
#include <QTableWidgetItem>

SelectGenre::SelectGenre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectGenre)
{
    ui->setupUi(this);
}

SelectGenre::~SelectGenre()
{
    delete ui;
}

void SelectGenre::setGenresData(const QVector<Genre> &genres)
{
    genresData = genres;

    // Clear existing data in the tableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(genresData.size());

    // Set headers
    QStringList headers = {"ID", "Genre"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Populate the table with genresData
    for (int row = 0; row < genresData.size(); ++row) {
        const Genre &genre = genresData[row];

        // Add genre data to each column in the current row
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(genre.id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(genre.name));
    }
}

void SelectGenre::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    // Retrieve the selected genre and emit a signal
    selectedGenre = ui->tableWidget->item(item->row(), 1)->text(); // Retrieve the genre name from the second column
    emit genreSelected(selectedGenre);
}


QString SelectGenre::getSelectedGenre() const
{
    return selectedGenre;
}
