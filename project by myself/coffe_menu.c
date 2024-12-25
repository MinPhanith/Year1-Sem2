#include <stdio.h>
int main() {
    float price, total = 0.0;
    int drink, qty, choice;

    printf("----------Welcome to our cafe-----------\n");
    
    // Loop for ordering drinks
    do {
        printf("Which would you like to drink today?\n");
        printf("----------These are our menu------------\n");
        printf("1. Ice latte\n2. Ice Cappuccino\n3. Ice Americano\n4. Green tea\n");
        printf("Input the numbers of menu that you want (0 to finish ordering): ");
        scanf("%d", &drink);
        
        if (drink == 0) {
            break; // Exit the loop if user enters 0
        }
        
        switch(drink) {
            case 1:
                printf("Ice latte price per one: $2.00\n");
                printf("Qty: ");
                scanf("%d", &qty);
                price = 2.00;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            case 2:
                printf("Ice Cappuccino price per one: $3.00\n");
                printf("Qty: ");
                scanf("%d", &qty);
                price = 3.00;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            case 3:
                printf("Ice Americano price per one: $4.00\n");
                printf("Qty: ");
                scanf("%d", &qty);
                price = 4.00;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            case 4:
                printf("Green Tea price per one: $1.5\n");
                printf("Qty: ");
                scanf("%d", &qty);
                price = 1.5;
                total += qty * price; // Add total for this drink to overall total
                break;
            
            default:
                printf("Invalid choice!\n");
                continue; // Restart the loop if an invalid choice is entered
        }
        
        printf("Drink added to your order.\n");
        
        // Ask if user wants to order more drinks
        printf("Do you want to order more drinks? (1: Yes, 0: No): ");
        scanf("%d", &choice);
        
    } while (choice != 0);
    
    // Display the total if any drinks were ordered
    if (total > 0.0) {
        printf("Your total is $%.2f\n", total);
    } else {
        printf("No drinks ordered. Have a good day!\n");
    }
    
    return 0; // Exit the program successfully
}
