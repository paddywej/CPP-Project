#include "borrowinfo.h"

BorrowInfo::BorrowInfo()
{
    // Default constructor
}

BorrowInfo::BorrowInfo(const QString &bookISBN, const QString &memberID, const QDate &borrowDate, const QDate &returnDate, const QString &notes)
    : m_bookISBN(bookISBN), m_memberID(memberID), m_borrowDate(borrowDate), m_returnDate(returnDate), m_notes(notes)
{
    // Constructor with parameters
}

QString BorrowInfo::getBookISBN() const
{
    return m_bookISBN;
}

QString BorrowInfo::getMemberID() const
{
    return m_memberID;
}

QDate BorrowInfo::getBorrowDate() const
{
    return m_borrowDate;
}

QDate BorrowInfo::getReturnDate() const
{
    return m_returnDate;
}

QString BorrowInfo::getNotes() const
{
    return m_notes;
}

void BorrowInfo::setBookISBN(const QString &isbn)
{
    m_bookISBN = isbn;
}

void BorrowInfo::setMemberID(const QString &id)
{
    m_memberID = id;
}

void BorrowInfo::setBorrowDate(const QDate &date)
{
    m_borrowDate = date;
}

void BorrowInfo::setReturnDate(const QDate &date)
{
    m_returnDate = date;
}

void BorrowInfo::setNotes(const QString &notes)
{
    m_notes = notes;
}
