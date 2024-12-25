#include <iostream>

int main() {
    float price, total = 0.0;
    int drink, qty, choice;

    std::cout << "----------Welcome to our cafe-----------\n";

    // Loop for ordering drinks
    do {
        std::cout << "Which would you like to drink today?\n";
        std::cout << "----------These are our menu------------\n";
        std::cout << "1. Ice latte\n2. Ice Cappuccino\n3. Ice Americano\n4. Green tea\n";
        std::cout << "Input the numbers of menu that you want (0 to finish ordering): ";
        std::cin >> drink;
        
        if (drink == 0) {
            break; // Exit the loop if user enters 0
        }
        
        switch(drink) {
            case 1:
                std::cout << "Ice latte price per one: $2.00\n";
                std::cout << "Qty: ";
                std::cin >> qty;
                price = 2.00;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            case 2:
                std::cout << "Ice Cappuccino price per one: $3.00\n";
                std::cout << "Qty: ";
                std::cin >> qty;
                price = 3.00;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            case 3:
                std::cout << "Ice Americano price per one: $4.00\n";
                std::cout << "Qty: ";
                std::cin >> qty;
                price = 4.00;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            case 4:
                std::cout << "Green Tea price per one: $1.50\n";
                std::cout << "Qty: ";
                std::cin >> qty;
                price = 1.50;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            default:
                std::cout << "Invalid choice!\n";
                continue; // Restart the loop if an invalid choice is entered
        }
        
        std::cout << "Drink added to your order.\n";
        
        // Ask if user wants to order more drinks
        std::cout << "Do you want to order more drinks? (1: Yes, 0: No): ";
        std::cin >> choice;
        
    } while (choice != 0);
    
    // Display the total if any drinks were ordered
    if (total > 0.0) {
        std::cout << "Your total is $" << total << "\n";
    } else {
        std::cout << "No drinks ordered. Have a good day!\n";
    }
    
    return 0; // Exit the program successfully
}

