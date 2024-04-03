#ifndef USERS_H
#define USERS_H

#include <QString>

class Users {
public:
    Users(const QString& username, const QString& name, const QString& password);
    QString getUsername() const;
    QString getName() const;
    QString getPassword() const;
private:
    QString username;
    QString name;
    QString password;
};

#endif // USERS_H
