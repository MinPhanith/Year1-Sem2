#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;
    bool isBorrowed;

    Book() : id(0), title(""), author(""), year(0), isBorrowed(false) {}

    void input() {
        cout << "Enter book ID: ";
        cin >> id;
        cin.ignore();  // to ignore the newline character left in the input buffer

        cout << "Enter book title: ";
        getline(cin, title);

        cout << "Enter book author: ";
        getline(cin, author);

        cout << "Enter year of publication: ";
        cin >> year;

        isBorrowed = false;  // New book is not borrowed
    }

    void display() const {
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nYear: " << year;
        cout << "\nStatus: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class Library {
private:
    string filename;

public:
    Library(const string& file) : filename(file) {}

    void addBook();
    void viewBooks();
    void searchBook();
    void deleteBook();
    void borrowBook();
    void returnBook();
};

void Library::addBook() {
    ofstream file(filename, ios::app);
    Book book;
    book.input();

    file << book.id << "\n" << book.title << "\n" << book.author << "\n" << book.year << "\n" << book.isBorrowed << "\n";
    file.close();

    cout << "Book added successfully!\n";
}

void Library::viewBooks() {
    ifstream file(filename);
    Book book;
    bool found = false;

    while (file >> book.id) {
        file.ignore();
        getline(file, book.title);
        getline(file, book.author);
        file >> book.year;
        file >> book.isBorrowed;

        book.display();
        cout << "----------------------\n";
        found = true;
    }

    if (!found) {
        cout << "No books found.\n";
    }

    file.close();
}

void Library::searchBook() {
    ifstream file(filename);
    Book book;
    int id;
    bool found = false;

    cout << "Enter book ID to search: ";
    cin >> id;

    while (file >> book.id) {
        file.ignore();
        getline(file, book.title);
        getline(file, book.author);
        file >> book.year;
        file >> book.isBorrowed;

        if (book.id == id) {
            book.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }

    file.close();
}

void Library::deleteBook() {
    ifstream file(filename);
    ofstream temp("temp.txt");
    Book book;
    int id;
    bool found = false;

    cout << "Enter book ID to delete: ";
    cin >> id;

    while (file >> book.id) {
        file.ignore();
        getline(file, book.title);
        getline(file, book.author);
        file >> book.year;
        file >> book.isBorrowed;

        if (book.id != id) {
            temp << book.id << "\n" << book.title << "\n" << book.author << "\n" << book.year << "\n" << book.isBorrowed << "\n";
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (found) {
        cout << "Book deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void Library::borrowBook() {
    ifstream file(filename);
    ofstream temp("temp.txt");
    Book book;
    int id;
    bool found = false;

    cout << "Enter book ID to borrow: ";
    cin >> id;

    while (file >> book.id) {
        file.ignore();
        getline(file, book.title);
        getline(file, book.author);
        file >> book.year;
        file >> book.isBorrowed;

        if (book.id == id) {
            if (book.isBorrowed) {
                cout << "Book is already borrowed.\n";
            } else {
                book.isBorrowed = true;
                cout << "Book borrowed successfully.\n";
            }
            found = true;
        }

        temp << book.id << "\n" << book.title << "\n" << book.author << "\n" << book.year << "\n" << book.isBorrowed << "\n";
    }

    if (!found) {
        cout << "Book not found.\n";
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void Library::returnBook() {
    ifstream file(filename);
    ofstream temp("temp.txt");
    Book book;
    int id;
    bool found = false;

    cout << "Enter book ID to return: ";
    cin >> id;

    while (file >> book.id) {
        file.ignore();
        getline(file, book.title);
        getline(file, book.author);
        file >> book.year;
        file >> book.isBorrowed;

        if (book.id == id) {
            if (!book.isBorrowed) {
                cout << "Book was not borrowed.\n";
            } else {
                book.isBorrowed = false;
                cout << "Book returned successfully.\n";
            }
            found = true;
        }

        temp << book.id << "\n" << book.title << "\n" << book.author << "\n" << book.year << "\n" << book.isBorrowed << "\n";
    }

    if (!found) {
        cout << "Book not found.\n";
    }

    file.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

int main() {
    Library lib("library.txt");
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Borrow Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.viewBooks();
                break;
            case 3:
                lib.searchBook();
                break;
            case 4:
                lib.deleteBook();
                break;
            case 5:
                lib.borrowBook();
                break;
            case 6:
                lib.returnBook();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}
