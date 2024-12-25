#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void readdatafromfile() {
    string array[20];

    // Read from the text file
    ifstream MyReadFile("TestC++.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, array)) {
        // Output the text from the file
        cout << array<<endl;
    }

    // Close the file
    MyReadFile.close();
}

int main() {
    
    readdatafromfile();
    return 0;
}
