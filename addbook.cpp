#include "addbook.h"
#include "ui_addbook.h"
#include "selectauthor.h"
#include "selectgenre.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include "custommessagebox.h"
#include <QDesktopServices>
#include <QUrl>

// Define booksVector outside of the class declaration
QVector<Book> addbook::booksVector;

addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Book");
}

addbook::~addbook()
{
    delete ui;
}

void addbook::on_pushButton_5_clicked()
{
    QString Name = ui->text_name->text();
    QString ISBN = ui->text_ISBN->text();
    QString Author = ui->text_author->text();
    QString Genre = ui->text_genre->text();
    QString Publisher = ui->text_publisher->text();
    QString Price = ui->text_price->text();
    QString Quantity = ui->text_quantity->text();
    QString Date = ui->text_date->text();
    QString Description = ui->text_description->toPlainText();

    // Check if any required field is empty
    if (Name.isEmpty() || ISBN.isEmpty() || Author.isEmpty() || Genre.isEmpty() ||
        Publisher.isEmpty() || Price.isEmpty() || Quantity.isEmpty() || Date.isEmpty() || Description.isEmpty()) {
        CustomMessageBox::warning(this, tr("Warning"), tr("Please fill out all the information."));
        return;
    }

    // Create a new book instance
    Book newBook;
    newBook.name = Name;
    newBook.ISBN = ISBN;
    newBook.author = Author;
    newBook.genre = Genre;
    newBook.publisher = Publisher;
    newBook.price = Price;
    newBook.quantity = Quantity;
    newBook.date = Date;
    newBook.description = Description;

    // Assign the current image path to the new book
    newBook.imagePath = currentImagePath;

    // Add the new book to the vector of books
    booksVector.push_back(newBook);

    close();
}

void addbook::on_image_button_clicked()
{
    // Open file dialog to select an image file
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    // Check if the user selected a valid file
    if (imagePath.isEmpty()) {
        CustomMessageBox::warning(this, tr("Warning"), tr("No image selected."));
        return;
    }

    // Create a QPixmap object to hold the image
    QPixmap pixmap(imagePath);

    // Check if loading the image was successful
    if (pixmap.isNull()) {
        CustomMessageBox::warning(this, tr("Warning"), tr("Failed to load image."));
        return;
    }

    // Scale the pixmap to fit within the frame size of 340 x 192
    pixmap = pixmap.scaled(340, 192, Qt::KeepAspectRatio);

    // Create a QGraphicsPixmapItem to display the image
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

    // Create a QGraphicsScene to hold the pixmapItem
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addItem(pixmapItem);

    // Set the scene to the QGraphicsView
    ui->graphicsView->setScene(scene);

    // Save the path of the selected image to the currentImagePath
    currentImagePath = imagePath;
}

void addbook::on_chooseAuthorButton_clicked()
{
    // Open the selectauthor window
    SelectAuthor selectAuthorWindow;
    selectAuthorWindow.setAuthorsData(manageauthors.getAllAuthors());
    connect(&selectAuthorWindow, &SelectAuthor::authorSelected, this, &addbook::handleAuthorSelected);
    selectAuthorWindow.exec();
}

void addbook::handleAuthorSelected(const QString &author)
{
    ui->text_author->setText(author);
}

void addbook::on_chooseGenreButton_clicked()
{
    // Open the selectgenre window
    SelectGenre selectGenreWindow;
    selectGenreWindow.setGenresData(managegenres.getAllGenres());
    connect(&selectGenreWindow, &SelectGenre::genreSelected, this, &addbook::handleGenreSelected); // Corrected connection
    selectGenreWindow.exec();
}

void addbook::handleGenreSelected(const QString &genre)
{
    ui->text_genre->setText(genre);
}


QVector<Book>& addbook::getAllBooks() const {
    return booksVector;
}



