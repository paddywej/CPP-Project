#include "newpassword.h"
#include "ui_newpassword.h"

#include <QMessageBox>

NewPassword::NewPassword(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewPassword)
{
    ui->setupUi(this);
}

NewPassword::~NewPassword()
{
    delete ui;
}

void NewPassword::on_confirmButton_clicked()
{
    QString username = ui->username->text();
    QString name = ui->name->text();
    QString password = ui->newPass->text();

    if (username.isEmpty() && password.isEmpty())
    {
        QMessageBox::information(this, "Forgot Password", "Cannot be empty.");
    }
    else
    {
        mainwindow = new MainWindow(this);
        mainwindow->show();
    }

}


void NewPassword::on_backButton_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

