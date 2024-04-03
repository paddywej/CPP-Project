// handback.cpp
#include "handback.h"
#include "ui_handback.h"
#include "custommessagebox.h"
#include "addbook.h"
#include "borrowinfo.h"
#include "borrow.h" // Include the header file where borrow class is declared
#include <QDateTime>

handback::handback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::handback)
{
    ui->setupUi(this);
    this->setWindowTitle("Return Book");
}

handback::~handback()
{
    delete ui;
}

void handback::on_returnButton_clicked()
{
    QString isbn = ui->bookISBNLineEdit->text();

    // Find the book
    for (Book &book : addbook::booksVector) {
        if (book.ISBN == isbn) {
            // Increase the quantity of the book
            book.quantity = QString::number(book.quantity.toInt() + 1);

            // Get the borrow information of the book
            for (const BorrowInfo &borrowInfo : borrow::getBorrowedBooks()) { // Access borrowedBooks using getBorrowedBooks()
                if (borrowInfo.getBookISBN() == isbn) {
                    // Calculate if the book was returned late
                    QDate currentDate = QDate::currentDate();
                    if (currentDate > borrowInfo.getReturnDate()) {
                        // Book returned late, show custom message box
                        QString lateMessage = "The member returned the book late.\n"
                                              "Current date: " + currentDate.toString() + "\n"
                                                                         "Due date: " + borrowInfo.getReturnDate().toString();
                        CustomMessageBox::warning(this, tr("Late Return"), lateMessage);
                    }
                    break; // No need to continue searching for borrowed books
                }
            }

            // Show success message and update status label
            ui->statusLabel->setText("Book Returned");
            CustomMessageBox::information(this, tr("Information"), tr("Book returned successfully."));
            return;
        }
    }
    // If the book is not found
    CustomMessageBox::warning(this, tr("Warning"), tr("Book with ISBN not found."));
}

void handback::on_lostButton_clicked()
{
    QString isbn = ui->bookISBNLineEdit->text();

    // Find the book
    for (const Book &book : addbook::booksVector) {
        if (book.ISBN == isbn) {
            // Display the information of the lost book
            QTableWidgetItem *isbnItem = new QTableWidgetItem(book.ISBN);
            QTableWidgetItem *nameItem = new QTableWidgetItem(book.name);
            QTableWidgetItem *authorItem = new QTableWidgetItem(book.author);
            QTableWidgetItem *genreItem = new QTableWidgetItem(book.genre);
            QTableWidgetItem *publisherItem = new QTableWidgetItem(book.publisher);
            QTableWidgetItem *priceItem = new QTableWidgetItem(book.price);
            QTableWidgetItem *quantityItem = new QTableWidgetItem("1"); // Assuming quantity is always 1
            QTableWidgetItem *dateItem = new QTableWidgetItem(book.date);
            QTableWidgetItem *descriptionItem = new QTableWidgetItem(book.description);

            // Assuming you have a QTableWidget named lostBookTable
            int row = ui->lostBookTable->rowCount();
            ui->lostBookTable->insertRow(row);
            ui->lostBookTable->setItem(row, 0, isbnItem);
            ui->lostBookTable->setItem(row, 1, nameItem);
            ui->lostBookTable->setItem(row, 2, authorItem);
            ui->lostBookTable->setItem(row, 3, genreItem);
            ui->lostBookTable->setItem(row, 4, publisherItem);
            ui->lostBookTable->setItem(row, 5, priceItem);
            ui->lostBookTable->setItem(row, 6, quantityItem);
            ui->lostBookTable->setItem(row, 7, dateItem);
            ui->lostBookTable->setItem(row, 8, descriptionItem);

            // Update status label
            ui->statusLabel->setText("Reported Lost Book!");
            return;
        }
    }
    // If the book is not found
    CustomMessageBox::warning(this, tr("Warning"), tr("Book with ISBN not found."));
}


