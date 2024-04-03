#include "info.h"
#include "addbook.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Info::saveData(const QVector<Users>& librarianVec, const QVector<Author>& authors, const QVector<Genre>& genres, const QVector<Book>& booksVector, const QVector<Member>& membersVector) {
    QString fullFilename = "data.txt"; // Append ".txt" extension
    std::ofstream outFile(fullFilename.toStdString()); // Use fullFilename here
    if (outFile.is_open()) {
        // Save librarians
        for (const auto& librarian : librarianVec) {
            outFile << "Librarian:" << librarian.getName().toStdString() << ',' << librarian.getUsername().toStdString() << ',' << librarian.getPassword().toStdString() << '\n';
        }
        // Save authors
        for (const auto& author : authors) {
            outFile << "Author:" << author.id.toStdString() << ',' << author.firstName.toStdString() << ',' << author.lastName.toStdString() << ',' << author.expertise.toStdString() << ',' << author.about.toStdString() << '\n';
        }
        // Save genres
        for (const auto& genre : genres) {
            outFile << "Genre:" << genre.id.toStdString() << ',' << genre.name.toStdString() << '\n';
        }
        // Save books
        for (const auto& book : booksVector) {
            outFile << "Book:" << book.ISBN.toStdString() << ',' << book.name.toStdString() << book.author.toStdString() << ',' << book.genre.toStdString()  << book.publisher.toStdString() << ',' << book.price.toStdString() <<
                book.quantity.toStdString() << ',' << book.date.toStdString() << book.description.toStdString() << ',' << book.imagePath.toStdString() << book.borrowDate.toStdString() << ',' << book.returnDate.toStdString()
                    << ',' << book.notes.toStdString() << book.status.toStdString() << '\n';
        }
        // Save members
        for (const auto& member : membersVector) {
            outFile << "Book:" << member.ID.toStdString() << ',' << member.firstName.toStdString() << member.lastName.toStdString() << ',' << member.phone.toStdString() << member.email.toStdString() << ',' << member.gender.toStdString()
                    << member.borrowDate.toStdString() << ',' << member.returnDate.toStdString() << member.notes.toStdString() << '\n';
        }

        // Close the file after writing
        outFile.close();
        std::cout << "Data saved successfully.\n";

    } else {
        std::cerr << "Error opening file for writing: " << fullFilename.toStdString() << '\n'; // Use fullFilename here
    }
}

void Info::loadData(QVector<Users>& librarianVec, QVector<Author>& authors, QVector<Genre>& genres, QVector<Book> &booksVector, QVector<Member> &membersVector) {
    // void Info::loadData() {
    std::ifstream inFile("data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file" << std::endl;
        return;
    }

    // Clear existing data before loading
    librarianVec.clear();
    authors.clear();
    genres.clear();
    booksVector.clear();
    membersVector.clear();

    std::string line;
    while (std::getline(inFile, line) && line[0] != '/') {
        std::istringstream iss(line);
        std::string type;
        std::getline(iss, type, ':'); // Extract data type
        if (type == "Librarian") {
            std::string username, name, password;
            std::getline(iss, username, ','); // Extract username
            std::getline(iss, name, ','); // Extract name
            std::getline(iss, password); // Extract password
            librarianVec.push_back(Users(QString::fromStdString(username), QString::fromStdString(name), QString::fromStdString(password)));
        } else if (type == "Author") {
            std::string id, firstName, lastName, expertise, about;
            std::getline(iss, id, ','); // Extract id
            std::getline(iss, firstName, ','); // Extract first name
            std::getline(iss, lastName, ','); // Extract last name
            std::getline(iss, expertise, ','); // Extract expertise
            std::getline(iss, about); // Extract about
            authors.push_back(Author{QString::fromStdString(id), QString::fromStdString(firstName), QString::fromStdString(lastName), QString::fromStdString(expertise), QString::fromStdString(about)});
        } else if (type == "Genre") {
            std::string id, name;
            std::getline(iss, id, ','); // Extract id
            std::getline(iss, name); // Extract name
            genres.push_back(Genre{QString::fromStdString(id), QString::fromStdString(name)});
        } else if (type == "Book") { // Load book information
            std::string ISBN, name, author, genre, publisher, price, quantity, date, description, imagePath, borrowDate, returnDate, notes, status;
            std::getline(iss, ISBN, ',');
            std::getline(iss, name, ',');
            std::getline(iss, author, ',');
            std::getline(iss, genre, ',');
            std::getline(iss, publisher, ',');
            std::getline(iss, price, ',');
            std::getline(iss, quantity, ',');
            std::getline(iss, date, ',');
            std::getline(iss, description, ',');
            std::getline(iss, imagePath, ',');
            std::getline(iss, borrowDate, ',');
            std::getline(iss, returnDate, ',');
            std::getline(iss, notes, ',');
            std::getline(iss, status);
            booksVector.push_back(Book{QString::fromStdString(ISBN), QString::fromStdString(name), QString::fromStdString(author), QString::fromStdString(genre), QString::fromStdString(publisher), QString::fromStdString(price), QString::fromStdString(quantity), QString::fromStdString(date), QString::fromStdString(description), QString::fromStdString(imagePath), QString::fromStdString(borrowDate), QString::fromStdString(returnDate), QString::fromStdString(notes), QString::fromStdString(status)});
        } else if (type == "Member") { // Load member information
            std::string ID, firstName, lastName, phone, email, gender, borrowDate, returnDate, notes;
            std::getline(iss, ID, ',');
            std::getline(iss, firstName, ',');
            std::getline(iss, lastName, ',');
            std::getline(iss, phone, ',');
            std::getline(iss, email, ',');
            std::getline(iss, gender, ',');
            std::getline(iss, borrowDate, ',');
            std::getline(iss, returnDate, ',');
            std::getline(iss, notes);
            membersVector.push_back(Member{QString::fromStdString(ID), QString::fromStdString(firstName), QString::fromStdString(lastName), QString::fromStdString(phone), QString::fromStdString(email), QString::fromStdString(gender), QString::fromStdString(borrowDate), QString::fromStdString(returnDate), QString::fromStdString(notes)});
            // Unknown data type
            std::cerr << "Unknown data type: " << type << std::endl;
        }
    }

    inFile.close(); // Close the file
}
