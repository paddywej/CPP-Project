#ifndef MANAGEGENRES_H
#define MANAGEGENRES_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QTableView>


struct Genre {
    QString id;
    QString name;
};


namespace Ui {
class ManageGenres;
}

class ManageGenres : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageGenres(QWidget *parent = nullptr);
    ~ManageGenres();
    QVector<Genre>& getAllGenres() const;


private slots:
    void on_addButton_clicked();

    void populateTableWithGenres(); //adds genres to the table

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_backButton_clicked();

private:
    Ui::ManageGenres *ui;
    static QVector<Genre> genres; //vector of genres
    // QTableView *genreTableView;
};

#endif // MANAGEGENRES_H
