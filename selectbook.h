// selectbook.h
#ifndef SELECTBOOK_H
#define SELECTBOOK_H

#include <QDialog>
#include "addbook.h"
#include "addbook.h"
#include <QTableWidgetItem>

namespace Ui {
class SelectBook;
}

class SelectBook : public QDialog
{
    Q_OBJECT

public:
    explicit SelectBook(QWidget *parent = nullptr);
    ~SelectBook();

    void setBooksData(const QVector<Book> &books);

signals:
    void bookSelected(const Book &selectedBook);

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::SelectBook *ui;
    QVector<Book> booksVector;
};

#endif // SELECTBOOK_H

