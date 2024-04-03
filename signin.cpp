#include "signin.h"
#include "ui_signin.h"
#include <custommessagebox.h>
#include "info.h"

SignIn::SignIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign In");
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_signInButton_clicked()
{
    QString username_input = ui->username->text();
    QString name_input = ui->name->text();
    QString password_input = ui->password->text();

    const QString constant_username = "librarian";
    const QString constant_password = "password1234";

    if (username_input != constant_username || password_input != constant_password)
    {
        CustomMessageBox::warning(this, "Sign in", "Incorrect username or password.");
        return;
    }

    else if (username_input.isEmpty() || name_input.isEmpty() || password_input.isEmpty())
    {
        CustomMessageBox::information(this, "Sign in", "This cannot be empty.");
        return;
    }

    // Add librarian to the list
    librarianVec.push_back(Users(username_input, name_input, password_input));

    Info info;

    for (const auto& librarian : librarianVec) {
        if (librarian.getUsername() == username_input && librarian.getPassword() == password_input) {
            CustomMessageBox::information(this, "Sign in", "Sign in successful. Welcome!");

            info.loadData(librarianVec, authors, genres, booksVector, membersVector);

            hide();
            MainWindow *mainwindow = new MainWindow();
            mainwindow->show();

        }
    }
}

QVector<Users>& SignIn::getAllLibrarians() const {
    return librarianVec;
}

QVector<Users> SignIn::librarianVec;
