#include <iostream>
#include <fstream>
using namespace std;
//====================================================================
void ReadDataFromFileToArray() {
    ifstream MyReadfile("array.txt", ios::in);
    if (!MyReadfile.is_open()) {
        cout << "Error: Could not open the file\n";
        return;
    }

    int Array[100];
    int size = 0;

    // Reading the array elements from the file
    while (MyReadfile >> Array[size]) {
        ++size;
    }

    MyReadfile.close();

    // Displaying the array elements
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << Array[i] << " ";
    }
    cout << endl;
}
//============================================================================
void WriteDataFromArrayToFile() {
    ofstream Mywritefile("array.txt", ios::app);
    if (!Mywritefile.is_open()) {
        cout << "Failed to open file for writing.\n";
        return;
    }

    int Array[100];
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    if (size > 100 || size <= 0) {
        cout << "Invalid size. Please enter a value between 1 and 100.\n";
        Mywritefile.close();
        return;
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> Array[i];
        Mywritefile << Array[i] << " ";
    }

    Mywritefile.close();
}
//=============================================================================================
int main() {
    int op;
    cout << "1. WriteDataFromArrayToFile\n2. ReadDataFromFileToArray" << endl;
    cout << "Choose one option: ";
    cin >> op;
    switch (op) {
        case 1:
            WriteDataFromArrayToFile();
            break;
        case 2:
            ReadDataFromFileToArray();
            break;
        default:
            cout << "Invalid option" << endl;
    }
    return 0;
}
