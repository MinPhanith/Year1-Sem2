#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct User {
    string username;
    string password;
};

struct Book {
    string name;
    string author;
    int pages;
    int yearReleased;
    int availableCopies;
    int ID_Book;
};

vector<Book> library;
vector<User> users;

class LibraryManager {
private:
    string loggedInUser;
public:
    LibraryManager() : loggedInUser("") {}

    void loadUsers() {
        ifstream infile("users.txt");
        if (infile.is_open()) {
            User user;
            while (infile >> user.username >> user.password) {
                users.push_back(user);
            }
            infile.close();
        }
    }

    void saveUsers() {
        ofstream outfile("users.txt", ios::app);
        if (outfile.is_open()) {
            for (const auto& user : users) {
                outfile << user.username << " " << user.password << endl;
            }
            outfile.close();
        }
    }

    void loadBooks() {
        ifstream infile("books.txt");
        if (infile.is_open()) {
            Book book;
            while (infile >> book.name >> book.author >> book.pages >> book.yearReleased >> book.availableCopies>>book.ID_Book) {
                library.push_back(book);
            }
            infile.close();
        }
    }

    void saveBooks() {
        ofstream outfile("books.txt");
        if (outfile.is_open()) {
            for (const auto& book : library) {
                outfile << book.name << " " << book.author << " " 
                        << book.pages << " " << book.yearReleased << " " <<book.ID_Book<<" "
                        << book.availableCopies << endl;
            }
            outfile.close();
        }
    }

    string inputWithMask() {
        string input;
        char ch;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') { 
                if (!input.empty()) {
                    cout << "\b \b"; 
                    input.pop_back();
                }
            } else {
                input.push_back(ch);
                cout << '*';
            }
        }
        cout << endl;
        return input;
    }

    bool authenticate(const string& username, const string& password) {
        for (const auto& user : users) {
            if (user.username == username && user.password == password) {
                return true;
            }
        }
        return false;
    }

    bool login() {
        string username, password;

        cout << "Enter username: ";
        cin.ignore(); 
        getline(cin, username);

        cout << "Enter password: ";
        password = inputWithMask();

        if (authenticate(username, password)) {
            cout << "Login successful." << endl;
            loggedInUser = username;
            return true;
        } else {
            cout << "Invalid username or password." << endl;
            return false; 
        }
    }

    void registerUser() {
        User newUser;
        cout << "Enter new username: "; cin >> newUser.username;
        cout << "Enter new password: "; newUser.password = inputWithMask();
        users.push_back(newUser);
        saveUsers();
        cout << "User registered successfully!" << endl;
    }

    void viewBookList() {
        cout << setw(20) << "Book_ID" << setw(20) << "Name" << setw(20) << "Author" << setw(10) << "Pages"
             << setw(15) << "Year Released" << setw(15) << "Available Copies" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        for (const auto& book : library) {
            cout << setw(20) << book.ID_Book<< setw(20) << book.name << setw(20) << book.author << setw(10) << book.pages
                 << setw(15) << book.yearReleased << setw(15) << book.availableCopies << endl;
        }
    }

    void viewBookDetails() {
        string bookName;
        cout << "Enter book name: "; cin.ignore(); getline(cin, bookName);
        for (const auto& book : library) {
            if (book.name == bookName) {
                cout << "ID_Book: " << book.ID_Book << endl;
                cout << "Name: " << book.name << endl;
                cout << "Author: " << book.author << endl;
                cout << "Pages: " << book.pages << endl;
                cout << "Year Released: " << book.yearReleased << endl;
                cout << "Available Copies: " << book.availableCopies << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void addBook() {
        Book newBook;
        cout << "Enter book name: "; cin.ignore(); getline(cin, newBook.name);
        cout << "Enter author name: "; getline(cin, newBook.author);
        cout << "Enter number of pages: "; cin >> newBook.pages;
        cout << "Enter year released: "; cin >> newBook.yearReleased;
        cout << "Enter available copies: "; cin >> newBook.availableCopies;
        cout<<"Enter Book_ID:";cin>> newBook.ID_Book;
        library.push_back(newBook);
        saveBooks();
        cout << "Book added successfully!" << endl;
    }

    void deleteBook() {
        string bookName;
        cout << "Enter book name to delete: "; cin.ignore(); getline(cin, bookName);
        for (auto it = library.begin(); it != library.end(); ++it) {
            if (it->name == bookName) {
                library.erase(it);
                saveBooks();
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void editBookAmount() {
        string bookName;
        int newAmount;
        cout << "Enter book name to edit: "; cin.ignore(); getline(cin, bookName);
        for (auto& book : library) {
            if (book.name == bookName) {
                cout << "Enter new amount: "; cin >> newAmount;
                book.availableCopies = newAmount;
                saveBooks();
                cout << "Book amount updated successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void lendBook() {
        string bookName;
        cout << "Enter book name to lend: "; cin.ignore(); getline(cin, bookName);
        for (auto& book : library) {
            if (book.name == bookName && book.availableCopies > 0) {
                book.availableCopies--;
                saveBooks();
                cout << "Book lent successfully!" << endl;
                return;
            }
        }
        cout << "Book not found or no copies available!" << endl;
    }

    void returnBook() {
        string bookName;
        cout << "Enter book name to return: "; cin.ignore(); getline(cin, bookName);
        for (auto& book : library) {
            if (book.name == bookName) {
                book.availableCopies++;
                saveBooks();
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void manageLibrary() {
        int choice = 1;

        while (choice != 0) {
            cout << "1. View Book List" << endl;
            cout << "2. View Book Details" << endl;
            cout << "3. Add Book" << endl;
            cout << "4. Delete Book" << endl;
            cout << "5. Edit Book Amount" << endl;
            cout << "6. Lend Book" << endl;
            cout << "7. Return Book" << endl;
            cout << "0. Logout" << endl;
            cout << "Choose the option: "; cin >> choice;
            system("cls");

            switch (choice) {
                case 1:
                    viewBookList();
                    break;
                case 2:
                    viewBookDetails();
                    break;
                case 3:
                    addBook();
                    break;
                case 4:
                    deleteBook();
                    break;
                case 5:
                    editBookAmount();
                    break;
                case 6:
                    lendBook();
                    break;
                case 7:
                    returnBook();
                    break;
                case 0:
                    cout << "Logging out..." << endl;
                    loggedInUser = "";
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }

            if (choice != 0) {
                cout << "Press any key to continue..." << endl;
                _getch();
                system("cls");
            }
        }
    }
};

int main() {
    LibraryManager libraryManager;
    libraryManager.loadUsers();
    libraryManager.loadBooks();

    int choice = 1;
    while (choice != 0) {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the option: "; cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                if (libraryManager.login()) {
                    libraryManager.manageLibrary();
                }
                break;
            case 2:
                libraryManager.registerUser();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        if (choice != 0) {
            cout << "Press any key to continue..." << endl;
            _getch();
            system("cls");
        }
    }

    return 0;
}
