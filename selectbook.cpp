// selectbook.cpp
#include "selectbook.h"
#include "ui_selectbook.h"

SelectBook::SelectBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectBook)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &SelectBook::on_tableWidget_itemDoubleClicked);
}

SelectBook::~SelectBook()
{
    delete ui;
}

void SelectBook::setBooksData(const QVector<Book> &books)
{
    booksVector = books;

    // Clear existing data in the tableWidget
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(booksVector.size());

    // Set headers
    QStringList headers = {"ID", "Title", "Author", "Genre", "Date", "Quantity", "Description"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Populate the table with booksData
    for (int row = 0; row < booksVector.size(); ++row) {
        const Book &book = booksVector[row];

        // Add book data to each column in the current row
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(book.ISBN));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(book.name));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(book.author));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(book.genre));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(book.date));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(book.quantity));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(book.description));
    }
}

void SelectBook::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    // Retrieve the selected book and emit a signal
    int row = item->row();
    if (row >= 0 && row < booksVector.size()) {
        const Book &selectedBook = booksVector[row];
        emit bookSelected(selectedBook);
        this->accept(); // Close the dialog after selection
    }
}


