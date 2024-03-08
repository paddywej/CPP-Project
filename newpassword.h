#ifndef NEWPASSWORD_H
#define NEWPASSWORD_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class NewPassword;
}

class NewPassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewPassword(QWidget *parent = nullptr);
    ~NewPassword();

private slots:
    void on_confirmButton_clicked();

    void on_backButton_clicked();

private:
    Ui::NewPassword *ui;
    MainWindow *mainwindow;
};

#endif // NEWPASSWORD_H
