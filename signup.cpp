#include "signup.h"
#include "ui_signup.h"

#include <QMessageBox>
#include "login.h"
#include "mainwindow.h"
// #include <QDebug>
// #include <QRegExpression>
// #include <QRegExpValidator>

Signup::Signup(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign Up");
    // setValidator();
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_createAccButton_clicked()
{
    QString username = ui->username->text();
    QString name = ui->name->text();
    QString password = ui->password->text();

    if (username.isEmpty() && password.isEmpty() && name.isEmpty())
    {
        QMessageBox::information(this, "Sign up", "Cannot be empty.");
    }

    else
    {
        mainwindow = new MainWindow(this);
        mainwindow->show();
    }
}


void Signup::on_backButton_clicked()
{
    this->hide();
    Login login;
    login.show();
}

