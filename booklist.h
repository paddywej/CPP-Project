// booklist.h
#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QDialog>
#include <QVector>
#include "addbook.h" // Include the header file where Book is defined

namespace Ui {
class Booklist;
}

class Booklist : public QDialog
{
    Q_OBJECT

public:
    explicit Booklist(QWidget *parent = nullptr);
    ~Booklist();

private slots:
    void on_searchButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::Booklist *ui;

    // Function to update book information on the right side of the window
    void updateBookInformation(const Book &book);

    // Function to populate the table with book information
    void populateTable();

    // Function to clear book information on the right side of the window
    void clearBookInformation();
};

#endif // BOOKLIST_H
