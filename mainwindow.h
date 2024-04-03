// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "addbook.h"
#include "addmember.h"
#include "deletebook.h"
#include "managegenres.h"
#include "manageauthors.h"
#include "users.h"

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

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void updateTotalBookCount();

private slots:
    void on_manageGenresButton_clicked();
    void on_manageAuthorsButton_clicked();
    void on_manageAuthorsButton_3_clicked();
    void on_manageAuthorsButton_4_clicked();
    void on_manageAuthorsButton_5_clicked();
    void on_manageAuthorsButton_6_clicked();
    void on_manageAuthorsButton_8_clicked();
    void on_manageAuthorsButton_7_clicked();
    void on_manageAuthorsButton_10_clicked();
    void on_manageAuthorsButton_2_clicked();
    void on_manageAuthorsButton_9_clicked();
    void on_manageAuthorsButton_11_clicked();
    void removeBookCover(const QString &isbn);

private:
    Ui::MainWindow *ui;
    ManageGenres *managegenres;
    ManageAuthors *manageauthors;
    QVector<Users> librarianVec;
    QVector<Author> authors;
    QVector<Genre> genres;
    QVector<Book> booksVector;
    QVector<Member> membersVector;
    void updateBookDisplay();
    DeleteBook *deleteBook;
};

#endif // MAINWINDOW_H
