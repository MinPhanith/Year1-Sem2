#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Student//Creat a class name student
{
    public:
        string name;//
        int age;//
        int year;//
        string department;//Theses are Data member of class studend we can call them as attributes
        string studyshift;//
        string classname;//

//void input is a member fucntion and we can call it method
       void input() {
            cout << "Enter name : ";
            
            getline(cin, name);
            cout << "Enter age : ";
            cin >> age;
            cout << "Enter year : ";
            cin >> year;
            cout << "Enter department : ";
            cin.ignore(); // Clear the newline character left by previous inputs
            getline(cin, department);
            cout << "Enter study shift : ";
            getline(cin, studyshift); // Use getline to handle spaces
            cout << "Enter class name: ";
            getline(cin, classname);
}

//void outputtofile is a member fucntion and we can call it method too
        void InputToFile() {
            ofstream outfile("StudentInformation.txt",ios::app);//ofstream is a stream class and outfile is name of object
//ios::app is mode
            if (outfile.is_open()) {
                
                outfile << " Name : " << name << endl;
                outfile << " Age : " << age << endl;
                outfile << " Year : " << year << endl;
                outfile << " Department : " << department << endl;
                outfile << " Study shift : " << studyshift << endl;
                outfile << " Class : " << classname << endl;
                outfile.close();
                cout << "All data of student  recorded to StudentInformation.txt" << endl;
            } else {
                cout << "Unable to open file for writing." << endl;
            }
        }
};

int main()
{
    
    system("cls");
    string a = ".";
    Student Datastudent; //Creates an instance of the Student class name Datastudent
    Datastudent.input();// Calls the input() method of the student object to gather student information from the user.

    cout <<"Processing";
    for(int i = 0; i < 15; i++){
        Sleep(1000);
        cout <<a;
    }
    cout << endl;
    Datastudent.InputToFile(); //Calls the outputToFile() method to write the collected student information to the file
    return 0;
}
