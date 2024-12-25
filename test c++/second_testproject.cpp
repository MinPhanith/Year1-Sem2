#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool loaned;
};

void addBook() {
    Book book;
    ofstream file("library.txt", ios::app);

    cout << "Enter Book ID: ";
    cin >> book.id;
    cin.ignore();  // To consume the newline character after entering ID
    cout << "Enter Book Title: ";
    getline(cin, book.title);
    cout << "Enter Book Author: ";
    getline(cin, book.author);
    book.loaned = false;

    file << book.id << "," << book.title << "," << book.author << "," << book.loaned << endl;
    file.close();

    cout << "Book added successfully.\n";
}

void displayBooks() {
    ifstream file("library.txt");
    string line;
    Book book;

    cout << "Book ID\tTitle\tAuthor\tLoaned\n";
    cout << "-------------------------------------\n";
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);

        book.id = stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.loaned = stoi(line.substr(pos3 + 1));

        cout << book.id << "\t" << book.title << "\t" << book.author << "\t" << (book.loaned ? "Yes" : "No") << endl;
    }
    file.close();
}

void searchBook() {
    ifstream file("library.txt");
    string line;
    Book book;
    int searchId;
    bool found = false;

    cout << "Enter Book ID to search: ";
    cin >> searchId;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);

        book.id = stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.loaned = stoi(line.substr(pos3 + 1));

        if (book.id == searchId) {
            cout << "Book found:\n";
            cout << "ID: " << book.id << "\nTitle: " << book.title << "\nAuthor: " << book.author << "\nLoaned: " << (book.loaned ? "Yes" : "No") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }
    file.close();
}

void deleteBook() {
    ifstream file("library.txt");
    ofstream tempFile("temp.txt");
    string line;
    Book book;
    int deleteId;
    bool found = false;

    cout << "Enter Book ID to delete: ";
    cin >> deleteId;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);

        book.id = stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.loaned = stoi(line.substr(pos3 + 1));

        if (book.id == deleteId) {
            found = true;
        } else {
            tempFile << book.id << "," << book.title << "," << book.author << "," << book.loaned << endl;
        }
    }

    file.close();
    tempFile.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found) {
        cout << "Book deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void loanBook() {
    ifstream file("library.txt");
    ofstream tempFile("temp.txt");
    string line;
    Book book;
    int loanId;
    bool found = false;

    cout << "Enter Book ID to loan: ";
    cin >> loanId;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);

        book.id = stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.loaned = stoi(line.substr(pos3 + 1));

        if (book.id == loanId) {
            if (!book.loaned) {
                book.loaned = true;
                found = true;
                cout << "Book loaned successfully.\n";
            } else {
                cout << "Book is already loaned.\n";
            }
        }
        tempFile << book.id << "," << book.title << "," << book.author << "," << book.loaned << endl;
    }

    file.close();
    tempFile.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found) {
        cout << "Book not found.\n";
    }
}

void returnBook() {
    ifstream file("library.txt");
    ofstream tempFile("temp.txt");
    string line;
    Book book;
    int returnId;
    bool found = false;

    cout << "Enter Book ID to return: ";
    cin >> returnId;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);

        book.id = stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.loaned = stoi(line.substr(pos3 + 1));

        if (book.id == returnId) {
            if (book.loaned) {
                book.loaned = false;
                found = true;
                cout << "Book returned successfully.\n";
            } else {
                cout << "Book is not currently loaned.\n";
            }
        }
        tempFile << book.id << "," << book.title << "," << book.author << "," << book.loaned << endl;
    }

    file.close();
    tempFile.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found) {
        cout << "Book not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Loan Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                loanBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
