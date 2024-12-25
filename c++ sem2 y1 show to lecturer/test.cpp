#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

class Student {
public:
    string name;
    int age;
    int year;
    string department;
    string studyshift;
    string classname;

    void input() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // Clear the buffer before taking string input
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter study shift: ";
        getline(cin, studyshift);
        cout << "Enter class name: ";
        getline(cin, classname);
    }

    void display() {
        cout << "Name: " << name << "\nAge: " << age << "\nYear: " << year
             << "\nDepartment: " << department << "\nStudy shift: " << studyshift
             << "\nClass: " << classname << endl;
    }
};

void saveStudentToFile(Student &student) {
    ofstream outfile("StudentInformation.txt", ios::app);
    if (outfile.is_open()) {
        outfile << "Name: " << student.name << "\n"
                << "Age: " << student.age << "\n"
                << "Year: " << student.year << "\n"
                << "Department: " << student.department << "\n"
                << "Study shift: " << student.studyshift << "\n"
                << "Class: " << student.classname << "\n\n";
        outfile.close();
        cout << "Student data saved successfully!" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void displayAllStudents() {
    ifstream infile("StudentInformation.txt");
    if (!infile.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(infile, line)) {
        if (line.rfind("Name: ", 0) == 0) {
            cout << "Student " << ++count << ":\n";
        }
        cout << line << endl;
    }

    infile.close();
}

void editStudent() {
    ifstream infile("StudentInformation.txt");
    ofstream tempFile("temp.txt");

    if (!infile.is_open() || !tempFile.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    string line, targetName;
    bool found = false;

    cout << "Enter the name of the student to edit: ";
    cin.ignore();
    getline(cin, targetName);

    while (getline(infile, line)) {
        if (line.find("Name: ") != string::npos && line.substr(6) == targetName) {
            found = true;
            cout << "Editing student: " << targetName << endl;
            Student student;
            student.input();
            tempFile << "Name: " << student.name << "\n"
                     << "Age: " << student.age << "\n"
                     << "Year: " << student.year << "\n"
                     << "Department: " << student.department << "\n"
                     << "Study shift: " << student.studyshift << "\n"
                     << "Class: " << student.classname << "\n\n";
            getline(infile, line); // Skip the current student's other details
        } else {
            tempFile << line << "\n";
        }
    }

    infile.close();
    tempFile.close();
    remove("StudentInformation.txt");
    rename("temp.txt", "StudentInformation.txt");

    if (found) {
        cout << "Student data updated successfully!" << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

void deleteStudent() {
    ifstream infile("StudentInformation.txt");
    ofstream tempFile("temp.txt");

    if (!infile.is_open() || !tempFile.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    string line, targetName;
    bool found = false;

    cout << "Enter the name of the student to delete: ";
    cin.ignore();
    getline(cin, targetName);

    while (getline(infile, line)) {
        if (line.find("Name: ") != string::npos && line.substr(6) == targetName) {
            found = true;
            cout << "Deleting student: " << targetName << endl;
            getline(infile, line); // Skip the current student's other details
        } else {
            tempFile << line << "\n";
        }
    }

    infile.close();
    tempFile.close();
    remove("StudentInformation.txt");
    rename("temp.txt", "StudentInformation.txt");

    if (found) {
        cout << "Student data deleted successfully!" << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

int main() {
    int choice;
    do {
        system("cls");
        cout << "School Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Edit Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                student.input();
                saveStudentToFile(student);
                break;
            }
            case 2:
                displayAllStudents();
                system("pause");
                break;
            case 3:
                editStudent();
                system("pause");
                break;
            case 4:
                deleteStudent();
                system("pause");
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
                system("pause");
        }
    } while (choice != 5);

    return 0;
}
