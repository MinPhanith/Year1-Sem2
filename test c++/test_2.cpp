#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

class Book {
public:
    int bookID;
    std::string title;
    std::string author;
    bool isIssued;

    Book(int id, std::string t, std::string a)
        : bookID(id), title(t), author(a), isIssued(false) {}
};

class Student {
public:
    int studentID;
    std::string name;
    std::vector<int> issuedBooks;

    Student(int id, std::string n) : studentID(id), name(n) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Student> students;

public:
    void addBook(int id, std::string title, std::string author) {
        books.push_back(Book(id, title, author));
        std::cout << "Book added successfully.\n";
    }

    void deleteBook(int id) {
        auto it = std::remove_if(books.begin(), books.end(), [id](Book& book) {
            return book.bookID == id;
        });
        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "Book deleted successfully.\n";
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void searchBook(int id) {
        for (const auto& book : books) {
            if (book.bookID == id) {
                std::cout << "Book ID: " << book.bookID << ", Title: " << book.title
                          << ", Author: " << book.author << ", Issued: " << (book.isIssued ? "Yes" : "No") << std::endl;
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void displayBooks() {
        for (const auto& book : books) {
            std::cout << "Book ID: " << book.bookID << ", Title: " << book.title
                      << ", Author: " << book.author << ", Issued: " << (book.isIssued ? "Yes" : "No") << std::endl;
        }
    }

    void addStudent(int id, std::string name) {
        students.push_back(Student(id, name));
        std::cout << "Student added successfully.\n";
    }

    void deleteStudent(int id) {
        auto it = std::remove_if(students.begin(), students.end(), [id](Student& student) {
            return student.studentID == id;
        });
        if (it != students.end()) {
            students.erase(it, students.end());
            std::cout << "Student deleted successfully.\n";
        } else {
            std::cout << "Student not found.\n";
        }
    }

    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.studentID == id) {
                std::cout << "Student ID: " << student.studentID << ", Name: " << student.name << std::endl;
                return;
            }
        }
        std::cout << "Student not found.\n";
    }

    void displayStudents() {
        for (const auto& student : students) {
            std::cout << "Student ID: " << student.studentID << ", Name: " << student.name << std::endl;
        }
    }

    void issueBook(int studentID, int bookID) {
        for (auto& book : books) {
            if (book.bookID == bookID && !book.isIssued) {
                for (auto& student : students) {
                    if (student.studentID == studentID) {
                        book.isIssued = true;
                        student.issuedBooks.push_back(bookID);
                        std::cout << "Book issued successfully.\n";
                        return;
                    }
                }
                std::cout << "Student not found.\n";
                return;
            }
        }
        std::cout << "Book not found or already issued.\n";
    }

    void returnBook(int studentID, int bookID) {
        for (auto& book : books) {
            if (book.bookID == bookID && book.isIssued) {
                for (auto& student : students) {
                    if (student.studentID == studentID) {
                        book.isIssued = false;
                        auto it = std::find(student.issuedBooks.begin(), student.issuedBooks.end(), bookID);
                        if (it != student.issuedBooks.end()) {
                            student.issuedBooks.erase(it);
                            std::cout << "Book returned successfully.\n";
                            return;
                        }
                    }
                }
                std::cout << "Student not found.\n";
                return;
            }
        }
        std::cout << "Book not found or not issued.\n";
    }

    void loadData() {
        std::ifstream bookFile("books.txt");
        if (bookFile.is_open()) {
            int id;
            std::string title, author;
            bool isIssued;
            while (bookFile >> id >> title >> author >> isIssued) {
                books.push_back(Book(id, title, author));
                books.back().isIssued = isIssued;
            }
            bookFile.close();
        }

        std::ifstream studentFile("students.txt");
        if (studentFile.is_open()) {
            int id;
            std::string name;
            while (studentFile >> id >> name) {
                students.push_back(Student(id, name));
            }
            studentFile.close();
        }
    }

    void saveData() {
        std::ofstream bookFile("books.txt");
        for (const auto& book : books) {
            bookFile << book.bookID << " " << book.title << " " << book.author << " " << book.isIssued << "\n";
        }
        bookFile.close();

        std::ofstream studentFile("students.txt");
        for (const auto& student : students) {
            studentFile << student.studentID << " " << student.name << "\n";
        }
        studentFile.close();
    }

    void mainMenu() {
        loadData();
        int choice;
        while (true) {
            std::cout << "Library Management System\n";
            std::cout << "1. Add Book\n";
            std::cout << "2. Delete Book\n";
            std::cout << "3. Search Book\n";
            std::cout << "4. Display Books\n";
            std::cout << "5. Add Student\n";
            std::cout << "6. Delete Student\n";
            std::cout << "7. Search Student\n";
            std::cout << "8. Display Students\n";
            std::cout << "9. Issue Book\n";
            std::cout << "10. Return Book\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    int bookID;
                    std::string title, author;
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookID;
                    std::cout << "Enter Title: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Enter Author: ";
                    std::getline(std::cin, author);
                    addBook(bookID, title, author);
                    break;
                }
                case 2: {
                    int bookID;
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookID;
                    deleteBook(bookID);
                    break;
                }
                case 3: {
                    int bookID;
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookID;
                    searchBook(bookID);
                    break;
                }
                case 4: {
                    displayBooks();
                    break;
                }
                case 5: {
                    int studentID;
                    std::string name;
                    std::cout << "Enter Student ID: ";
                    std::cin >> studentID;
                    std::cout << "Enter Name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    addStudent(studentID, name);
                    break;
                }
                case 6: {
                    int studentID;
                    std::cout << "Enter Student ID: ";
                    std::cin >> studentID;
                    deleteStudent(studentID);
                    break;
                }
                case 7: {
                    int studentID;
                    std::cout << "Enter Student ID: ";
                    std::cin >> studentID;
                    searchStudent(studentID);
                    break;
                }
                case 8: {
                    displayStudents();
                    break;
                }
                case 9: {
                    int studentID, bookID;
                    std::cout << "Enter Student ID: ";
                    std::cin >> studentID;
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookID;
                    issueBook(studentID, bookID);
                    break;
                }
                case 10: {
                    int studentID, bookID;
                    std::cout << "Enter Student ID: ";
                    std::cin >> studentID;
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookID;
                    returnBook(studentID, bookID);
                    break;
                }
                case 0: {
                    saveData();
                    std::cout << "Exiting...\n";
                    return;
                }
                default: {
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
                }
            }
        }
    }
};

int main() {
    Library library;
    library.mainMenu();
    return 0;
}

