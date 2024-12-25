#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int code[20];
string name[20];
float price[20];
int qty[20];
float total[20];
int i, j, op, n;

//========================================================//
void input() {
    cout << "============product#" << i + 1 << "===============\n";
    cout << "Enter code: ";
    cin >> code[i];
    cout << "Enter Name product: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name[i]);
    cout << "Enter Price: ";
    cin >> price[i];
    cout << "Enter Qty: ";
    cin >> qty[i];
    total[i] = price[i] * qty[i];
}

//=======================================================//
void view() {
    for (i = 0; i < n; i++) {
        cout << "============product#" << i + 1 << "============\n";
        cout << "Code: " << code[i] << endl;
        cout << "Name product: " << name[i] << endl;
        cout << "Price: $" << fixed << setprecision(2) << price[i] << endl;
        cout << "Qty: " << qty[i] << " pcs\n";
        cout << "Total: $" << fixed << setprecision(2) << total[i] << endl;
    }
}

//===========================================================//
void pay() {
    cout << "================Total payment Information===============\n";
    float t = 0;
    for (i = 0; i < n; i++) {
        t += price[i] * qty[i];
    }
    cout << "Your payment is = $" << fixed << setprecision(2) << t << endl;
    cout << "=============Thank you, have a nice day!======================\n==============Hope to see you here again========================\n";
}

//==========================================================//
void search() {
    cout << "\n=====================Search product=================\n";
    int search;
    bool check = false;
    cout << "Enter the code of the product you want to search: ";
    cin >> search;
    for (i = 0; i < n; i++) {
        if (search == code[i]) {
            cout << "Code: " << code[i] << endl;
            cout << "Product Name: " << name[i] << endl;
            cout << "Price: $" << fixed << setprecision(2) << price[i] << endl;
            cout << "Qty: " << qty[i] << endl;
            check = true;
        }
    }
    if (check) {
        cout << "\n\e[4;32mSearch found!!\e[0;m\n";
    } else {
        cout << "\n\e[4;31mSearch Not found!!\e[0;m\n";
    }
}

//=======================================//
void updateProduct() {
    cout << "\n=====================Update Product=================\n";
    int up;
    cout << "Enter the code of the product that you want to update: ";
    cin >> up;
    for (i = 0; i < n; i++) {
        if (up == code[i]) {
            input();
        }
    }
}

//==================================================//
void deleteProduct() {
    int dnum, j;
    bool check = false;
    cout << "\n=============Delete Product============\n";
    cout << "Enter the code of the product that you want to delete: ";
    cin >> dnum;
    for (i = 0; i < n; i++) {
        if (dnum == code[i]) {
            for (j = i; j < n - 1; j++) {
                code[j] = code[j + 1];
                name[j] = name[j + 1];
                price[j] = price[j + 1];
                qty[j] = qty[j + 1];
                total[j] = total[j + 1];
            }
            n--;
            check = true;
            break;
        }
    }
    if (check) {
        cout << "\n\e[4;32m======**Delete Success!**=============\e[0;m\n";
    } else {
        cout << "\n\e[4;31m======**Delete fail!**==============\e[0;m\n";
    }
}

//==================================================//
void addProduct() {
    cout << "\n=====================Add more product=================\n";
    int Padd;
    cout << "How many products do you want to add more: ";
    cin >> Padd;
    for (i = n; i < n + Padd; i++) {
        input();
    }
    n += Padd;
}

int main() {
    do {
        cout << "1. Product information\n2. View product\n3. Payment\n4. Search product\n5. Update product\n6. Delete product\n7. Add more Product\n8. Exit\n";
        cout << "Please choose one option: ";
        cin >> op;
        switch (op) {
            case 1:
                cout << "Enter the number of products that you want: ";
                cin >> n;
                for (i = 0; i < n; i++) {
                    input();
                }
                break;
            case 2:
                view();
                break;
            case 3:
                pay();
                break;
            case 4:
                search();
                break;
            case 5:
                updateProduct();
                break;
            case 6:
                deleteProduct();
                break;
            case 7:
                addProduct();
                break;
            case 8:
                exit(0);
                break;
        }
    } while (op != 0);

    return 0;
}

