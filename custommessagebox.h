#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include "qabstractbutton.h"
#include <QMessageBox>
#include <QFont>

class CustomMessageBox : public QMessageBox
{
public:
    static void information(QWidget *parent, const QString &title, const QString &text) {
        CustomMessageBox messageBox(parent);
        messageBox.setWindowTitle(title);
        messageBox.setText(text);
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setStandardButtons(QMessageBox::Ok);

        // Change the font of the OK button
        QAbstractButton *okButton = messageBox.button(QMessageBox::Ok);
        QFont font("Comic Sans MS", 10);
        okButton->setFont(font);
        okButton->setStyleSheet("background-color: rgb(152, 164, 193); color: white;");

        messageBox.setStyleSheet("QMessageBox { background-color: #faf8f5; }");

        messageBox.exec();
    }

    static void warning(QWidget *parent, const QString &title, const QString &text) {
        CustomMessageBox messageBox(parent);
        messageBox.setWindowTitle(title);
        messageBox.setText(text);
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setStandardButtons(QMessageBox::Ok);


        // Change the font of the OK button
        QAbstractButton *okButton = messageBox.button(QMessageBox::Ok);
        QFont font("Comic Sans MS", 10);
        okButton->setFont(font);
        okButton->setStyleSheet("background-color: rgb(152, 164, 193); color: white;");

        messageBox.setStyleSheet("QMessageBox { background-color: #faf8f5; }");

        messageBox.exec();
    }

private:
    explicit CustomMessageBox(QWidget *parent = nullptr) : QMessageBox(parent) {
        // Set the font for the message box
        QFont font("Comic Sans MS", 10);
        this->setFont(font);
        this->setStyleSheet("color: rgb(100, 114, 121);");
    }
};

#endif // CUSTOMMESSAGEBOX_H
