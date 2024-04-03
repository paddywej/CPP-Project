// borrow.h
#ifndef BORROW_H
#define BORROW_H

#include <QDialog>
#include "addbook.h" // Include addbook.h here if you need to access addbook::booksVector
#include "borrowinfo.h" // Include the BorrowInfo class here

namespace Ui {
class borrow;
}

class borrow : public QDialog
{
    Q_OBJECT

public:
    explicit borrow(QWidget *parent = nullptr);
    ~borrow();

    static std::vector<BorrowInfo>& getBorrowedBooks();

signals:
    void bookBorrowed(const BorrowInfo &borrowedBook); // Use BorrowInfo class here

private slots:
    void on_confirmButton_clicked();
    void on_borrowBookButton_clicked();

private:
    Ui::borrow *ui;
    static std::vector<BorrowInfo> borrowedBooks;
};

#endif // BORROW_H






