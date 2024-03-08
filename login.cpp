#include "login.h"
#include "ui_login.h"
// #include "Database.h"
#include <QMessageBox>
#include<QSqlQuery>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{

    QString username = ui->username->text();
    QString password = ui->password->text();

    // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // db.setHostName("localhost");
    // db.setDatabaseName("library");
    // db.setUserName("root");
    // db.setPassword("");

    // if(!db.open()) {
    //     QMessageBox::information(this,"Database Connection","Database Not Connected");
    // }

    // QSqlQuery query;
    // query.prepare("SELECT * FROM account WHERE login = :username AND password = :password");
    // query.bindValue(":username", username);
    // query.bindValue(":password", password);
    // query.exec();

    // if(query.next()) {
    //     hide();
    //     mainwindow = new MainWindow(this);
    //     mainwindow->show();
    // } else {
    //    QMessageBox::information(this, "Login", "Cannot be empty.");
    // }

    // db.close();


    if (username.isEmpty() && password.isEmpty())
    {
        QMessageBox::information(this, "Login", "Cannot be empty.");
    }
    else
    {
        mainwindow = new MainWindow(this);
        mainwindow->show();
    }

}


void Login::on_signupButton_clicked()
{
    signup = new Signup(this);
    signup->show();
}


void Login::on_forgotpassButton_clicked()
{
    newpass = new NewPassword(this);
    newpass->show();
}

