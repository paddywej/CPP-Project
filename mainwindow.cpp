#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Library");
}

MainWindow::~MainWindow()
{
    delete ui;
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

