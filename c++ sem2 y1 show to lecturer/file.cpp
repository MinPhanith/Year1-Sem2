#include<iostream>
#include<fstream>
using namespace std;

string read;
//============================================
void writedatatofile(){
    // This line is used to create a file
    fstream Myfile("ITE DEPARTMENT.txt", ios::out);
    // This line is used to write to the file
    Myfile << "ITEM2!";
    Myfile.close();
}
//==============================================
void readdatafromfile(){
    // This line is used to read the file
    ifstream ReadMyfile("ITE DEPARTMENT.txt");
    if (ReadMyfile.is_open()) {
        getline(ReadMyfile, read);
        cout << read;
        ReadMyfile.close();
    } else {
        cout << "Unable to open file";
    }
}

int main(){
    writedatatofile();
    readdatafromfile();
    return 0;
}