#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <QDialog>
#include <QVector>
#include "addmember.h"

namespace Ui {
class Memberlist;
}

class Memberlist : public QDialog
{
    Q_OBJECT

public:
    explicit Memberlist(QWidget *parent = nullptr);
    ~Memberlist();

private slots:
    void on_searchButton_clicked();

private:
    Ui::Memberlist *ui;
};

#endif // MEMBERLIST_H
