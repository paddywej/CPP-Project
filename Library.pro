QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbook.cpp \
    addmember.cpp \
    booklist.cpp \
    borrow.cpp \
    borrowinfo.cpp \
    deletebook.cpp \
    deletemember.cpp \
    handback.cpp \
    info.cpp \
    main.cpp \
    mainwindow.cpp \
    manageauthors.cpp \
    managegenres.cpp \
    memberlist.cpp \
    selectauthor.cpp \
    selectbook.cpp \
    selectgenre.cpp \
    signin.cpp \
    users.cpp

HEADERS += \
    addbook.h \
    addmember.h \
    booklist.h \
    borrow.h \
    borrowinfo.h \
    custommessagebox.h \
    deletebook.h \
    deletemember.h \
    handback.h \
    info.h \
    mainwindow.h \
    manageauthors.h \
    managegenres.h \
    memberlist.h \
    selectauthor.h \
    selectbook.h \
    selectgenre.h \
    signin.h \
    users.h

FORMS += \
    addbook.ui \
    addmember.ui \
    booklist.ui \
    borrow.ui \
    deletebook.ui \
    deletemember.ui \
    handback.ui \
    mainwindow.ui \
    manageauthors.ui \
    managegenres.ui \
    memberlist.ui \
    selectauthor.ui \
    selectbook.ui \
    selectgenre.ui \
    signin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc

RC_ICONS = book.ico
