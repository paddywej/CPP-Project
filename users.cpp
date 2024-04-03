#include "users.h"

Users::Users(const QString& username, const QString& name, const QString& password)
    : username(username), name(name), password(password) {}

QString Users::getUsername() const {
    return username;
}

QString Users::getName() const {
    return name;
}

QString Users::getPassword() const {
    return password;
}
