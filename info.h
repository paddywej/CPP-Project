#ifndef INFO_H
#define INFO_H

#include <QVector>
#include "addbook.h"
#include "addmember.h"
#include "manageauthors.h"
#include "managegenres.h"
#include "users.h"

class Info {
public:
    // void saveData(const QVector<Users>& librarianVec);
    // void loadData(QVector<Users>& librarianVec);
    static void saveData(const QVector<Users>& librarianVec, const QVector<Author>& authors, const QVector<Genre>& genres, const QVector<Book>& booksVector, const QVector<Member>& membersVector);
    static void loadData(QVector<Users>& librarianVec, QVector<Author>& authors, QVector<Genre>& genres, QVector<Book> &booksVector, QVector<Member> &membersVector);
};

#endif // INFO_H
