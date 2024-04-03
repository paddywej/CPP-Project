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
    QVector<Author>& getAllAuthors() const;
    void loadDataFromInfo();

private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_backButton_clicked();

private:
    Ui::ManageAuthors *ui;
    static QVector<Author> authors;
    void populateTableWithAuthors();


};

#endif // MANAGEAUTHORS_H

