#ifndef SELECTGENRE_H
#define SELECTGENRE_H

#include <QDialog>
#include <QVector>
#include "managegenres.h"
#include "qtablewidget.h"

namespace Ui {
class SelectGenre;
}

class SelectGenre : public QDialog
{
    Q_OBJECT

public:
    explicit SelectGenre(QWidget *parent = nullptr);
    ~SelectGenre();

    void setGenresData(const QVector<Genre> &genres);
    QString getSelectedGenre() const;

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

signals:
    void genreSelected(const QString &selectedGenre);

private:
    Ui::SelectGenre *ui;
    QVector<Genre> genresData;
    QString selectedGenre;
};

#endif // SELECTGENRE_H

