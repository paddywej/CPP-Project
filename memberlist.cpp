#include "memberlist.h"
#include "ui_memberlist.h"
#include <QTableWidgetItem>

Memberlist::Memberlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Memberlist)
{
    ui->setupUi(this);
    this->setWindowTitle("Member List");

    // Set column headers for the table
    QStringList headers = {"ID", "First Name", "Last Name", "Phone", "Email", "Gender"};
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Populate the table with member information
    int row = 0;
    for (const Member &member : Addmember::MembersVector) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(member.ID));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(member.firstName));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(member.lastName));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(member.phone));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(member.email));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(member.gender));
        ++row;
    }
}

Memberlist::~Memberlist()
{
    delete ui;
}

void Memberlist::on_searchButton_clicked() {
    // Search for a member by ID
    QString searchID = ui->searchLineEdit->text();

    // Find the matching member ID in the table
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, 0)->text() == searchID) {
            // Select the matching row
            ui->tableWidget->selectRow(row);
            return;
        }
    }
}
