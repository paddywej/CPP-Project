// deletebook.cpp
#include "deletebook.h"
#include "addbook.h" // Include the header file where booksVector is defined
#include "mainwindow.h"
#include "ui_deletebook.h"
#include "custommessagebox.h"

DeleteBook::DeleteBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBook)
{
    ui->setupUi(this);
    this->setWindowTitle("Delete Book");
}

DeleteBook::~DeleteBook()
{
    delete ui;
}

void DeleteBook::on_pushButton_delete_clicked()
{
    QString isbnToDelete = ui->lineEdit_ISBN->toPlainText();
    for (int i = 0; i < addbook::booksVector.size(); ++i) {
        if (addbook::booksVector[i].ISBN == isbnToDelete) {
            addbook::booksVector.remove(i);
            CustomMessageBox::information(this, tr("Information"), tr("Book deleted successfully."));
            emit bookDeleted(isbnToDelete); // Emit the signal with ISBN
            // Call updateTotalBookCount() after deleting the book
            ((MainWindow*)parent())->updateTotalBookCount();
            return;
        }
    }
    CustomMessageBox::warning(this, tr("Warning"), tr("Book with ISBN not found."));
}



