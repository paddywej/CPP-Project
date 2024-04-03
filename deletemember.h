// deletemember.h
#ifndef DELETEMEMBER_H
#define DELETEMEMBER_H

#include <QDialog>
#include <QVector>
#include "addmember.h" // Include the header file where Member is defined

namespace Ui {
class Deletemember;
}

class Deletemember : public QDialog
{
    Q_OBJECT

public:
    explicit Deletemember(QWidget *parent = nullptr);
    ~Deletemember();

    // Declare MembersVector as a static member
    static QVector<Member> MembersVector;

signals:
    void memberDeleted(const QString &id);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Deletemember *ui;
};

#endif // DELETEMEMBER_H
