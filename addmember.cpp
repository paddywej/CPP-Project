// addmember.cpp
#include "addmember.h"
#include "ui_addmember.h"

QVector<Member> Addmember::MembersVector;

Addmember::Addmember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addmember)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Member");
}

Addmember::~Addmember()
{
    delete ui;
}

void Addmember::on_pushButton_clicked()
{
    QString FirstName = ui->firstname->text();
    QString LastName = ui->lastname->text();
    QString Phone = ui->phone->text();
    QString Email = ui->email->text();
    QString Gender = ui->gender->text();

    if (FirstName.isEmpty() || LastName.isEmpty() || Phone.isEmpty() || Email.isEmpty() || Gender.isEmpty()) {
        ui->text->setText("<font color='red'>Please enter all of the above</font>");
    } else {
        Member newMember;
        newMember.firstName = FirstName;
        newMember.lastName = LastName;
        newMember.phone = Phone;
        newMember.email = Email;
        newMember.gender = Gender;

        newMember.ID = QString::number(MembersVector.size() + 1);

        MembersVector.push_back(newMember);

        ui->text->setText("<font color='green'>Member Added!</font>");

        ui->firstname->clear();
        ui->lastname->clear();
        ui->phone->clear();
        ui->email->clear();
        ui->gender->clear();

        emit memberAdded(); // Emit the signal indicating that a member has been added

        close();
    }
}

QVector<Member>& Addmember::getAllMembers() {
    return MembersVector;
}

