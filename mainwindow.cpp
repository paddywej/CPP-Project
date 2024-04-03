//mainwindow.cpp
#include "mainwindow.h"
#include "addmember.h"
#include "booklist.h"
#include "borrow.h"
#include "deletemember.h"
#include "handback.h"
#include "memberlist.h"
#include "qgraphicsitem.h"
#include "ui_mainwindow.h"
#include "info.h"
#include "signin.h"
#include "addbook.h"
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Library");
    Info::loadData(librarianVec, authors, genres, booksVector, membersVector);

    updateBookDisplay();

    deleteBook = new DeleteBook(this);

    // Display the total number of books and members
    ui->bookCountLabel->setText(QString::number(addbook::booksVector.size()));

    connect(deleteBook, &DeleteBook::bookDeleted, this, &MainWindow::removeBookCover);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTotalBookCount()
{
    // Update the total book count label
    ui->bookCountLabel->setText(QString::number(addbook::booksVector.size()));
}

void MainWindow::updateBookDisplay() {
    // Clear the current book display
    QLayoutItem *child;
    while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Display the latest 6 books added to the inventory
    int count = 0;
    for (int i = addbook::booksVector.size() - 1; i >= 0 && count < 6; --i) {
        const Book &book = addbook::booksVector[i];
        QPixmap pixmap(book.imagePath);
        if (!pixmap.isNull()) {
            QGraphicsScene *scene = new QGraphicsScene;
            scene->addPixmap(pixmap.scaled(100, 150, Qt::KeepAspectRatio));

            QGraphicsView *view = new QGraphicsView(scene);
            view->setFixedSize(120, 170); // Adjust the size as needed
            ui->gridLayout->addWidget(view);

            ++count;
        }
    }

    // Update the total book count label
    updateTotalBookCount();
}

void MainWindow::on_manageAuthorsButton_4_clicked()
{
    deleteBook->exec();
}

void MainWindow::on_manageGenresButton_clicked()
{
    managegenres = new ManageGenres(this);
    managegenres->show();
}

void MainWindow::on_manageAuthorsButton_clicked()
{
    manageauthors = new ManageAuthors(this);
    manageauthors->show();
}

void MainWindow::on_manageAuthorsButton_5_clicked()
{
    Booklist booklist;
    booklist.setModal(true);
    booklist.exec();
}

void MainWindow::on_manageAuthorsButton_8_clicked()
{
    Deletemember deletemember;
    deletemember.setModal(true);
    deletemember.exec();
}


void MainWindow::on_manageAuthorsButton_7_clicked()
{
    Memberlist memberlist;
    memberlist.setModal(true);
    memberlist.exec();
}


void MainWindow::on_manageAuthorsButton_10_clicked()
{
    borrow borrow;
    borrow.setModal(true);
    borrow.exec();
}


void MainWindow::on_manageAuthorsButton_11_clicked()
{
    handback handback;
    handback.setModal(true);
    handback.exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Save data before closing
    SignIn signIn;
    ManageAuthors manageAuthors;
    ManageGenres manageGenres;
    addbook addbook;
    Addmember Addmember;
    Info info;
    info.saveData(signIn.getAllLibrarians(), manageAuthors.getAllAuthors(), manageGenres.getAllGenres(), addbook.getAllBooks(), Addmember.getAllMembers());
    event->accept();
}

void MainWindow::on_manageAuthorsButton_2_clicked()
{
    addbook addBook;
    addBook.setModal(true);
    addBook.exec();

    // Update book display and total book count label after adding a book
    updateBookDisplay();
}


void MainWindow::on_manageAuthorsButton_9_clicked()
{
    Addmember addmember;
    addmember.setModal(true);
    addmember.exec();
}

void MainWindow::removeBookCover(const QString &isbn) {
    // Remove the book cover from the QGraphicsView based on the ISBN
    for (int i = 0; i < ui->gridLayout->count(); ++i) {
        QGraphicsView *view = qobject_cast<QGraphicsView*>(ui->gridLayout->itemAt(i)->widget());
        if (view) {
            QGraphicsScene *scene = view->scene();
            if (scene && scene->items().size() > 0) {
                QGraphicsPixmapItem *item = nullptr;
                // Find the QGraphicsPixmapItem with the matching ISBN and remove it
                foreach (QGraphicsItem *sceneItem, scene->items()) {
                    item = dynamic_cast<QGraphicsPixmapItem*>(sceneItem);
                    if (item && item->data(Qt::UserRole).toString() == isbn) {
                        break;
                    }
                }
                if (item) {
                    scene->removeItem(item);
                    delete item;
                }
            }
        }
    }
}
