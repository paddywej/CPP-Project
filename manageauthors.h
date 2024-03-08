#ifndef MANAGEAUTHORS_H
#define MANAGEAUTHORS_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QTableView>

struct Author {
    QString id;
    QString firstName;
    QString lastName;
    QString expertise;
    QString about;
};

namespace Ui {
class ManageAuthors;
}

class ManageAuthors : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageAuthors(QWidget *parent = nullptr);
    ~ManageAuthors();

private slots:
    void on_addButton_clicked();

    void populateTableWithAuthors();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::ManageAuthors *ui;
    static QVector<Author> authors;

};

#endif // MANAGEAUTHORS_H
