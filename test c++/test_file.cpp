#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//==============================================================
void writeDatafromarrayTofile() {
    ofstream Mywritefile("TestC++.txt");
    
    // Check if file opened successfully
    if (!Mywritefile.is_open()) {
        cout << "Error: Could not open the file for writing!" << endl;
        return;
    }

    // Example array of strings to write to file
    string data[] = {"1", "3", "42","20", "30", "44","223", "340", "10","9", "90", "40"};
    int dataSize = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < dataSize; i++) {
        Mywritefile << data[i] << endl;
    }

    // Close the file
    Mywritefile.close();
}
//====================================================================
void readdatafromfileToarray() {
    string line;

    // Read from the text file
    ifstream MyReadFile("TestC++.txt");

    // Check if file opened successfully
    if (!MyReadFile.is_open()) {
        cout << "Error: Could not open the file!" << endl;
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
	cout<<"1.write Data from array To file\n2.read data from file To array\nChosse your option:";
	cin>>op;
	switch(op){
		case 1:
			 writeDatafromarrayTofile();
			break;
		case 2:
			readdatafromfileToarray();
		    break;	
	}
    return 0;
}

