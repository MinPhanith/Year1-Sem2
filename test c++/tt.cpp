#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeDatafromarrayTofile() {
    ofstream Mywritefile("TestC++.txt");
    
    // Check if file opened successfully
    if (!Mywritefile.is_open()) {
        cerr << "Error: Could not open the file for writing!" << endl;
        return;
    }

    int dataSize;
    cout << "Enter the number of elements you want to write to the file: ";
    cin >> dataSize;

    string* data = new string[dataSize]; // Dynamically allocate array

    for (int i = 0; i < dataSize; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data[i];
    }

    for (int i = 0; i < dataSize; i++) {
        Mywritefile << data[i] << endl;
    }

    // Clean up dynamically allocated memory
    delete[] data;

    // Close the file
    Mywritefile.close();
}
void readdatafromfileToarray() {
    string line;

    // Read from the text file
    ifstream MyReadFile("TestC++.txt");

    // Check if file opened successfully
    if (!MyReadFile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, line)) {
        // Output the text from the file
        cout << line << endl;
    }

    // Close the file
    MyReadFile.close();
}
int main() {
	int op;
	do{
	    cout << "1. Write Data from Array to File\n2. Read Data from File to Array\nChoose your option: ";
	    cin >> op;
		switch(op){
		case 1:
			 writeDatafromarrayTofile();
			break;
		case 2:
			readdatafromfileToarray();
		    break;	
	}	
	}while(op!=0);
	
    return 0;
}

