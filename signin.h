#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include "mainwindow.h"
#include "users.h"

namespace Ui {
class SignIn;
}

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();
    QVector<Users>& getAllLibrarians() const;


private slots:
    void on_signInButton_clicked();

private:
    Ui::SignIn *ui;
    MainWindow *mainwindow;
    static QVector<Users> librarianVec;
    QVector<Author> authors;
    QVector<Genre> genres;
    QVector<Book> booksVector;
    QVector<Member> membersVector;
};

#endif // SIGNIN_H
