#include<iostream>
#include<vector>
#include<string>

int qty;
float price, payment, total;
std::vector<std::string> items;
std::vector<int> quantities;

using namespace std;

void showbar() {
    cout << "==========>Nith Store<=========\n";
    cout << "1. Start Order\n2. View Order\n3. Payment\n4. Exit\n";
}

void order() {
    int menu;
    cout << "=========>Welcome to our menu<=============\n";
    cout << "1. Ice latte\n2. Ice Cappuccino\n3. Ice Americano\n4. Green tea\n";
    cout << "Input the numbers of menu that you want (0 to finish your order): ";
    cin >> menu;

    while (menu != 0) {
        string itemName;
        switch (menu) {
            case 1:
                price = 2.00;
                itemName = "Ice latte";
                break;
            case 2:
                price = 4.00;
                itemName = "Ice Cappuccino";
                break;
            case 3:
                price = 3.00;
                itemName = "Ice Americano";
                break;
            case 4:
                price = 5.00;
                itemName = "Green tea";
                break;
            default:
                cout << "Invalid selection! Try again.\n";
                continue;
        }

        cout << itemName << " per one price $" << price << endl;
        cout << "Input your qty: ";
        cin >> qty;

        payment += qty * price;
        items.push_back(itemName);
        quantities.push_back(qty);

        cout << "Your current payment is: $" << payment << endl;
        cout << "Input the numbers of menu that you want (0 to finish your order): ";
        cin >> menu;
    }
}

void vieworder() {
    cout << "This is the information of your order:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << items[i] << ": " << quantities[i] << " pcs\n";
    }
    cout << "Total payment: $" << payment << endl;
}

int main() {
    int op;
    showbar();
    cout << "Please choose one option: ";
    cin >> op;

    while (true) {
        switch (op) {
            case 1:
                order();
                break;
            case 2:
                vieworder();
                break;
            case 3:
                cout << "Payment functionality not implemented yet.\n";
                break;
            case 4:
                exit(0);
        }
        showbar();
        cout << "Please choose one option: ";
        cin >> op;
    }
}

