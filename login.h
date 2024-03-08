#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "signup.h"
#include "mainwindow.h"
#include "newpassword.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();

    void on_signupButton_clicked();

    void on_forgotpassButton_clicked();

private:
    Ui::Login *ui;
    Signup *signup;
    NewPassword *newpass;
    MainWindow *mainwindow;

};

#endif // LOGIN_H
