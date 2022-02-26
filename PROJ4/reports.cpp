#include "reports.h"

void report(){
    //declaring choice variable
    int choice = 0;

    while (choice != 7) {
        
        //printing the report
        cout << right << setw(20) << "\nSerendipity Booksellers\n" << setw(16) << "Reports\n\n";
        cout << "1.  Inventory Listing\n";
        cout << "2.  Inventory Wholesale Value\n";
        cout << "3.  Inventory Retail Value\n";
        cout << "4.  Listing by Quantity\n";
        cout << "5.  Listing by Cost\n";
        cout << "6.  Listing by Age\n";
        cout << "7.  Return to Main Menu\n\n";
        cout << "Enter Your Choice: ";

        //getting the user's choice with input validation
        do {
            cin >> choice;
            if (choice < 1 || choice > 7) {
                cout << "Invalid choice. (Please enter a number 1 - 7)\n";
                cout << "Enter your choice: ";
            }
        } while (choice < 1 || choice > 7);

        //switch statment to print the user's choice
        switch(choice) {
            case 1:
                repListing();
                break;
            case 2:
                repWholesale();
                break;
            case 3:
                repRetail();
                break;
            case 4:
                repQty();
                break;
            case 5:
                repCost();
                break;
            case 6:
                repAge();
                break;
            case 7:
                cout << "You selected item 7.";
                break;
        }
    }
}

//stub functions
void repListing() {
    cout << "You selected Inventory Listing.";
}

void repWholesale() {
    cout << "You selected Inventory Wholesale Value.";
}

void repRetail() {
    cout << "You selected Inventory Retail Value.";
}

void repQty() {
    cout << "You selected Listing by Quantity.";
}

void repCost() {
    cout << "You selected Listing by Cost.";
}

void repAge() {
    cout << "You selected Listing by Age.";
}