#include "login.h"
#include <QApplication>
// #include <QSqlDatabase>
// #include <QDebug>
// #include <QSqlError> // Include this header for QSqlError

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();

    // // Set up the database connection
    // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // db.setHostName("localhost");
    // db.setDatabaseName("your_database_name");
    // db.setUserName("your_username");
    // db.setPassword("your_password");

    // if (!db.open()) {
    //     qDebug() << "Failed to connect to database:";
    //     qDebug() << db.lastError().text();
    //     return -1;
    // }

    return a.exec();
}
