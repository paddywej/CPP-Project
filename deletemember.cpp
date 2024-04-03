// deletemember.cpp
#include "deletemember.h"
#include "ui_deletemember.h"
#include "addmember.h" // Include addmember.h here
#include "custommessagebox.h"

Deletemember::Deletemember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletemember)
{
    ui->setupUi(this);
    this->setWindowTitle("Delete Member");
}

Deletemember::~Deletemember()
{
    delete ui;
}

void Deletemember::on_pushButton_clicked()
{
    QString ID = ui->text_ID->text();
    for (int i = 0; i < Addmember::MembersVector.size(); ++i) {
        if (Addmember::MembersVector[i].ID == ID) {
            Addmember::MembersVector.remove(i);
            CustomMessageBox::information(this, tr("Information"), tr("Member deleted successfully."));
            // Emit the signal to indicate successful deletion
            emit memberDeleted(ID);
            return;
        }
    }
    CustomMessageBox::warning(this, tr("Warning"), tr("Member with this ID not found."));
}
