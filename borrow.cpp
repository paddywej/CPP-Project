#include "borrow.h"
#include "ui_borrow.h"
#include "custommessagebox.h"
#include "addbook.h" // Include addbook.h here to access addbook::booksVector
#include <QDateTime>

// Initialize the static borrowedBooks vector
std::vector<BorrowInfo> borrow::borrowedBooks;

borrow::borrow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::borrow)
{
    ui->setupUi(this);
    this->setWindowTitle("Borrow Book");
}

borrow::~borrow()
{
    delete ui;
}

void borrow::on_confirmButton_clicked()
{
    QString isbn = ui->bookISBNLineEdit->text();

    // Check if the book is available
    for (const Book &book : addbook::booksVector) {
        if (book.ISBN == isbn) {
            if (book.quantity.toInt() >= 1) {
                ui->availabilityLabel->setText("Available");
            } else {
                ui->availabilityLabel->setText("Unavailable");
            }
            return;
        }
    }
    // If the book is not found
    CustomMessageBox::warning(this, tr("Warning"), tr("Book with ISBN not found."));
}

void borrow::on_borrowBookButton_clicked()
{
    QString isbn = ui->bookISBNLineEdit->text();
    QString memberId = ui->memberIDLineEdit->text();
    QDate borrowDate = ui->borrowDateEdit->date();
    QDate returnDate = ui->returnDateEdit->date();
    QString notes = ui->notesTextEdit->toPlainText();

    // Find the book
    for (Book &book : addbook::booksVector) {
        if (book.ISBN == isbn) {
            // Check if the book is available
            if (book.quantity.toInt() >= 1) {
                // Decrease the quantity of the book
                book.quantity = QString::number(book.quantity.toInt() - 1);

                // Create a BorrowInfo object
                BorrowInfo borrowedBook(isbn, memberId, borrowDate, returnDate, notes); // Pass return time

                // Add the borrowed book to the static vector
                borrowedBooks.push_back(borrowedBook);

                // Emit signal with the borrowed book information
                emit bookBorrowed(borrowedBook);

                // Show success message
                CustomMessageBox::information(this, tr("Information"), tr("Book borrowed successfully."));
                return;
            } else {
                CustomMessageBox::warning(this, tr("Warning"), tr("Book is not available for borrowing."));
                return;
            }
        }
    }
    // If the book is not found
    CustomMessageBox::warning(this, tr("Warning"), tr("Book with ISBN not found."));
}

// Method to access borrowed books outside the class
std::vector<BorrowInfo>& borrow::getBorrowedBooks() {
    return borrowedBooks;
}
