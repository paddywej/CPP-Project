#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// #include <QtSql/QSqlDatabase>
// #include <QSqlQuery>
// #include<QSqlQueryModel>
// #include <QDir>

#include "managegenres.h"
#include "manageauthors.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
/*
    QSqlDatabase db;
    void connectDB()*/;
    // void setUsername(QString username);
    // void showBookNum();
    // void showMemberNum();
    // void showAuthorNum();
    // void showCover();

private slots:
    void on_manageGenresButton_clicked();

    void on_manageAuthorsButton_clicked();

private:
    Ui::MainWindow *ui;

    // QString filename = QDir::homePath()+ "/libraryDB.sqlite";

    // QString username;

    ManageGenres *managegenres;

    ManageAuthors *manageauthors;
};
#endif // MAINWINDOW_H
