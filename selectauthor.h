#include <QDialog>
#include <QVector>
#include "manageauthors.h"
#include "qtablewidget.h"

namespace Ui {
class SelectAuthor;
}

class SelectAuthor : public QDialog
{
    Q_OBJECT

public:
    explicit SelectAuthor(QWidget *parent = nullptr);
    ~SelectAuthor();

    void setAuthorsData(const QVector<Author> &authors);
    QString getSelectedAuthor();

signals:
    void authorSelected(const QString &author);

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::SelectAuthor *ui;
    QVector<Author> authorsData;
    QString selectedAuthor; // Declaration of selectedAuthor as a member variable
};

