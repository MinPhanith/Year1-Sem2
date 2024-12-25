#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addBook() {
    ofstream file("library.txt", ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string title, author;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);

    file << title << "," << author << ",0\n";
    file.close();
    cout << "Book added successfully!\n";
}

void listBooks() {
    ifstream file("library.txt");
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string line;
    int id = 1;
    cout << "Available Books:\n";
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);

        string title = line.substr(0, pos1);
        string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string isBorrowed = line.substr(pos2 + 1);

        if (isBorrowed == "0") {
            cout << "ID: " << id << ", Title: " << title
                 << ", Author: " << author << "\n";
        }
        id++;
    }
    file.close();
}

void updateBookStatus(int bookId, bool borrow) {
    ifstream file("library.txt");
    ofstream tempFile("temp.txt");
    if (!file || !tempFile) {
        cout << "Error opening file!\n";
        return;
    }

    string line;
    int id = 1;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);

        string title = line.substr(0, pos1);
        string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string isBorrowed = line.substr(pos2 + 1);

        if (id == bookId) {
            found = true;
            if (borrow && isBorrowed == "0") {
                isBorrowed = "1";
                cout << "You have borrowed: " << title << "\n";
            } else if (!borrow && isBorrowed == "1") {
                isBorrowed = "0";
                cout << "You have returned: " << title << "\n";
            } else {
                cout << (borrow ? "Book is already borrowed." : "This book wasn't borrowed.") << "\n";
            }
        }

        tempFile << title << "," << author << "," << isBorrowed << "\n";
        id++;
    }

    if (!found) {
        cout << "Book not found!\n";
    }

    file.close();
    tempFile.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");
}

void borrowBook() {
    int bookId;
    cout << "Enter book ID to borrow: ";
    cin >> bookId;
    updateBookStatus(bookId, true);
}

void returnBook() {
    int bookId;
    cout << "Enter book ID to return: ";
    cin >> bookId;
    updateBookStatus(bookId, false);
}

int main() {
    int choice;

    do {
        cout << "\nLibrary System Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. List Available Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
