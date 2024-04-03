#ifndef HANDBACK_H
#define HANDBACK_H

#include <QDialog>
#include <QTableWidgetItem>
#include "borrowinfo.h"

namespace Ui {
class handback;
}

class handback : public QDialog
{
    Q_OBJECT

public:
    explicit handback(QWidget *parent = nullptr);
    ~handback();

private slots:
    void on_returnButton_clicked();
    void on_lostButton_clicked();
    void updateTable(int index);
    void populateBorrowedBooksTable();

private:
    Ui::handback *ui;
    QList<BorrowInfo> borrowInfoList;
};

#endif // HANDBACK_H
