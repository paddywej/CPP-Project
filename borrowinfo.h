// borrowinfo.h
#ifndef BORROWINFO_H
#define BORROWINFO_H

#include <QString>
#include <QDate>
#include <QTime> // Include QTime header

class BorrowInfo
{
public:
    BorrowInfo();
    BorrowInfo(const QString &bookISBN, const QString &memberID, const QDate &borrowDate, const QDate &returnDate, const QString &notes); // Modify constructor to include QTime

    QString getBookISBN() const;
    QString getMemberID() const;
    QDate getBorrowDate() const;
    QDate getReturnDate() const;
    QString getNotes() const;

    void setBookISBN(const QString &isbn);
    void setMemberID(const QString &id);
    void setBorrowDate(const QDate &date);
    void setReturnDate(const QDate &date);
    void setNotes(const QString &notes);

private:
    QString m_bookISBN;
    QString m_memberID;
    QDate m_borrowDate;
    QDate m_returnDate;
    QTime m_returnTime; // Return time member variable
    QString m_notes;
};

#endif // BORROWINFO_H
