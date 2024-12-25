#include <iostream>
#include <fstream>
using namespace std;

class Item {
public:
    string data[5]; // Array to store data

    // Method to set data
    void setData(string arr[]) {
        for (int i = 0; i < 5; i++) {
            data[i] = arr[i];
        }
    }

    // Method to get data
    string* getData() {
        return data;
    }
};

// Function to write object data to file
void writedatatofile(Item item) {
    fstream Myfile("Reancpp.txt", ios::out);
    if (Myfile.is_open()) {
        for (int i = 0; i < 5; i++) {
            Myfile << item.data[i] << endl;
        }
        Myfile.close();
    } else {
        cout << "Unable to open file for writing";
    }
}

// Function to read data from file into object
void readdatafromfile(Item &item) {
    ifstream ReadMyfile("Reancpp.txt");
    if (ReadMyfile.is_open()) {
        for (int i = 0; i < 5; i++) {
            getline(ReadMyfile, item.data[i]);
        }
        ReadMyfile.close();
    } else {
        cout << "Unable to open file for reading";
    }
}

int main() {
    Item myItem;
    string myData[5] = {"Item1", "Item2", "Item3", "Item4", "Item5"};
    
    // Set data to the object
    myItem.setData(myData);
    
    // Write object data to file
    writedatatofile(myItem);

    // Create another Item object to read data into
    Item newItem;
    
    // Read data from file to object
    readdatafromfile(newItem);
    
    // Display the data read from the file
    string* dataRead = newItem.getData();
    for (int i = 0; i < 5; i++) {
        cout << dataRead[i] << endl;
    }

    return 0;
}
