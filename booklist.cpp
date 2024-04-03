// booklist.cpp
#include "booklist.h"
#include "ui_booklist.h"

Booklist::Booklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booklist)
{
    ui->setupUi(this);
    this->setWindowTitle("Book List");

    // Populate the table with book information
    populateTable();

    // Connect signals and slots
    connect(ui->searchButton, &QPushButton::clicked, this, &Booklist::on_searchButton_clicked);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &Booklist::on_tableWidget_cellClicked);
}

Booklist::~Booklist()
{
    delete ui;
}

void Booklist::populateTable() {
    // Clear any existing items in the table
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Set the column headers
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ISBN" << "Name" << "Author" << "Genre" << "Publisher" << "Price" << "Quantity" << "Date");

    // Populate the table with book information
    for (int i = 0; i < addbook::booksVector.size(); ++i) {
        const Book &book = addbook::booksVector[i];
        ui->tableWidget->insertRow(i);

        QTableWidgetItem *item;

        item = new QTableWidgetItem(book.ISBN);
        ui->tableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem(book.name);
        ui->tableWidget->setItem(i, 1, item);

        item = new QTableWidgetItem(book.author);
        ui->tableWidget->setItem(i, 2, item);

        item = new QTableWidgetItem(book.genre);
        ui->tableWidget->setItem(i, 3, item);

        item = new QTableWidgetItem(book.publisher);
        ui->tableWidget->setItem(i, 4, item);

        item = new QTableWidgetItem(book.price);
        ui->tableWidget->setItem(i, 5, item);

        item = new QTableWidgetItem(book.quantity);
        ui->tableWidget->setItem(i, 6, item);

        item = new QTableWidgetItem(book.date);
        ui->tableWidget->setItem(i, 7, item);
    }
}

void Booklist::on_searchButton_clicked() {
    // Get the ISBN from the search box
    QString ISBN = ui->searchBox->text();

    // Search for the ISBN in the table
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        if (ui->tableWidget->item(i, 0)->text() == ISBN) {
            // If found, select the row and update book information on the right side
            ui->tableWidget->selectRow(i);
            updateBookInformation(addbook::booksVector[i]);
            return;
        }
    }

    // If ISBN not found, clear book information
    clearBookInformation();
}

void Booklist::on_tableWidget_cellClicked(int row, int column) {
    Q_UNUSED(column);

    // Get the book information from the selected row
    Book book = addbook::booksVector[row];

    // Update the book information on the right side of the window
    updateBookInformation(book);
}

void Booklist::updateBookInformation(const Book &book) {
    // Update labels with book information
    ui->ISBNLabel->setText(book.ISBN);
    ui->nameLabel->setText(book.name);
    ui->authorLabel->setText(book.author);
    ui->genreLabel->setText(book.genre);
    ui->publisherLabel->setText(book.publisher);
    ui->priceLabel->setText(book.price);
    ui->quantityLabel->setText(book.quantity);
    ui->dateLabel->setText(book.date);

    // Display book cover if available
    if (!book.imagePath.isEmpty()) {
        QPixmap pixmap(book.imagePath);
        if (!pixmap.isNull()) {
            QGraphicsScene* scene = new QGraphicsScene(this);
            scene->addPixmap(pixmap);
            ui->graphicsView->setScene(scene);
        }
    } else {
        // Clear the graphics view if no image available
        ui->graphicsView->setScene(nullptr);
    }
}

void Booklist::clearBookInformation() {
    // Clear labels
    ui->ISBNLabel->clear();
    ui->nameLabel->clear();
    ui->authorLabel->clear();
    ui->genreLabel->clear();
    ui->publisherLabel->clear();
    ui->priceLabel->clear();
    ui->quantityLabel->clear();
    ui->dateLabel->clear();

    // Clear the graphics view
    ui->graphicsView->setScene(nullptr);
}
