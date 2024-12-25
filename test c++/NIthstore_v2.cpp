#include <iostream>

using namespace std;

int qty;
float price, payment, total;

void showbar() {
    cout << "==========> Nith Store <=========\n";
    cout << "1. Start Order\n2. View Order\n3. Payment\n4. Exit\n";
}

void order() {
    int menu;
    cout << "=========> Welcome to our menu <=============\n";
    cout << "1. Ice Latte\n2. Ice Cappuccino\n3. Ice Americano\n4. Green Tea\n";
    cout << "Input the number of the menu item you want (0 to finish your order): ";
    cin >> menu;
    while (menu != 0) {
        switch (menu) {
            case 1:
                price = 2.00;
                cout << "Ice Latte - $2.00 each\n";
                break;
            case 2:
                price = 4.00;
                cout << "Ice Cappuccino - $4.00 each\n";
                break;
            case 3:
                price = 3.00;
                cout << "Ice Americano - $3.00 each\n";
                break;
            case 4:
                price = 5.00;
                cout << "Green Tea - $5.00 each\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid menu item.\n";
                break;
        }

        if (menu >= 1 && menu <= 4) {
            cout << "Input your quantity: ";
            cin >> qty;
            payment += qty * price;
            cout << "Your current payment is: $" << payment << endl;
        }

        cout << "Input the number of the menu item you want (0 to finish your order): ";
        cin >> menu;
    }

    cout << "You have finished ordering! Have a nice day.\n";
}

void viewOrder() {
    cout << "Your total payment is: $" << payment << endl;
}

void paymentProcess() {
    cout << "Total payment due: $" << payment << endl;
    float amountPaid;
    cout << "Enter the amount paid: ";
    cin >> amountPaid;

    if (amountPaid >= payment) {
        cout << "Payment successful! Your change is: $" << amountPaid - payment << endl;
        payment = 0; // reset payment after successful transaction
    } else {
        cout << "Insufficient amount. Please pay at least: $" << payment << endl;
    }
}

int main() {
    int op;
    
    while (true) {
        showbar();
        cout << "Please choose one option: ";
        cin >> op;
        
        switch (op) {
            case 1:
                order();
                break;
            case 2:
                viewOrder();
                break;
            case 3:
                paymentProcess();
                break;
            case 4:
            	cout<<"========Ending order!==========";
                exit(0);
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}

