//addbook.h
#ifndef ADDBOOK_H
#define ADDBOOK_H

#include "manageauthors.h"
#include "managegenres.h"
#include <QDialog>
#include <QVector>

struct Book {
    QString ISBN;
    QString name;
    QString author;
    QString genre;
    QString publisher;
    QString price;
    QString quantity;
    QString date;
    QString description;
    QString imagePath;
    QString borrowDate;
    QString returnDate;
    QString notes;
    QString status;
};

namespace Ui {
class addbook;
}

class addbook : public QDialog
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();

    // Declare booksVector as a static member
    static QVector<Book> booksVector;
    QVector<Book>& getAllBooks() const;

private slots:
    void on_pushButton_5_clicked();
    void on_image_button_clicked();
    void on_chooseAuthorButton_clicked();
    void on_chooseGenreButton_clicked();
    void handleAuthorSelected(const QString &author);
    void handleGenreSelected(const QString &genre);

private:
    Ui::addbook *ui;
    ManageAuthors manageauthors;
    ManageGenres managegenres;

    // Path of the current image
    QString currentImagePath;
};

#endif // ADDBOOK_H

