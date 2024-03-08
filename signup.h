#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QDir>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <regex>
#include "mainwindow.h"

namespace Ui {
class Signup;
}

class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();
    void setValidator();

private slots:

    void on_createAccButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Signup *ui;

    MainWindow *mainwindow;
};

#endif // SIGNUP_H
