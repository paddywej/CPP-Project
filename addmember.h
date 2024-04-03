// addmember.h
#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QDialog>
#include <QVector>

struct Member {
    QString ID;
    QString firstName;
    QString lastName;
    QString phone;
    QString email;
    QString gender;
    QString borrowDate;
    QString returnDate;
    QString notes;
};

namespace Ui {
class Addmember;
}

class Addmember : public QDialog
{
    Q_OBJECT

public:
    explicit Addmember(QWidget *parent = nullptr);
    ~Addmember();

    Addmember(QVector<Member> &membersVector, QWidget *parent = nullptr);

    bool memberAdded() const;

signals:
    void memberAdded(); // Declaration of memberAdded signal

private slots:
    void on_pushButton_clicked();

public:
    static QVector<Member> MembersVector;

    static QVector<Member>& getAllMembers();

private:
    Ui::Addmember *ui;
};

#endif // ADDMEMBER_H
