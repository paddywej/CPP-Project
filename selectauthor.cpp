#include "selectauthor.h"
#include "ui_selectauthor.h"
#include <QTableWidgetItem>

SelectAuthor::SelectAuthor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectAuthor)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &SelectAuthor::on_tableWidget_itemDoubleClicked);
}

SelectAuthor::~SelectAuthor()
{
    delete ui;
}

void SelectAuthor::setAuthorsData(const QVector<Author> &authors)
{
    authorsData = authors;

    // Clear existing data in the tableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(authorsData.size());

    // Set headers
    QStringList headers = {"ID", "First Name", "Last Name", "Expertise", "About"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Populate the table with authorsData
    for (int row = 0; row < authorsData.size(); ++row) {
        const Author &author = authorsData[row];

        // Add author data to each column in the current row
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(author.id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(author.firstName));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(author.lastName));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(author.expertise));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(author.about));
    }
}

void SelectAuthor::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    // Retrieve the selected author and emit a signal
    QString selectedAuthorId = ui->tableWidget->item(item->row(), 0)->text(); // Retrieve the author ID from the first column
    QString selectedAuthorFirstName = ui->tableWidget->item(item->row(), 1)->text(); // Retrieve the first name from the second column
    QString selectedAuthorLastName = ui->tableWidget->item(item->row(), 2)->text(); // Retrieve the last name from the third column
    QString selectedAuthor = selectedAuthorFirstName + " " + selectedAuthorLastName; // Combine first name and last name
    emit authorSelected(selectedAuthor);
}

QString SelectAuthor::getSelectedAuthor()
{
    return selectedAuthor;
}
