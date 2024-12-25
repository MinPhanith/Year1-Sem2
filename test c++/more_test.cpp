#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  // Create a text file
  ofstream MyFile("filename.txt");

  // Write to the file
  MyFile << "ITE M2!";
 
  // Close the file
  MyFile.close();

  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyFile("filename.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyFile, myText)) {
    // Output the text from the file
    cout << myText;
  }

  // Close the file
  MyFile.close();
}

