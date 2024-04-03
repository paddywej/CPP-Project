#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QDialog>

namespace Ui {
class DeleteBook;
}

class DeleteBook : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteBook(QWidget *parent = nullptr);
    ~DeleteBook();

signals:
    void bookDeleted(const QString &isbn);

private slots:
    void on_pushButton_delete_clicked();

private:
    Ui::DeleteBook *ui;
};

#endif // DELETEBOOK_H
