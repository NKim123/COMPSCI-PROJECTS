#include <iostream>
#include <iomanip>
using namespace std;
void printReport();

int main(){
    printReport();
}

void printReport(){
    //declaring choice variable
    int choice = 0;

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
        if (choice != 7) {
            cout << "Invalid choice. (Please enter a number 1 - 7)\n";
            cout << "Enter your choice: ";
        }
    } while (choice != 7);

    //switch statment to print the user's choice
    switch(choice) {
        case 1:
            cout << "You selected item 1.";
            break;
        case 2:
            cout << "You selected item 2.";
            break;
        case 3:
            cout << "You selected item 3.";
            break;
        case 4:
            cout << "You selected item 4.";
            break;
        case 5:
            cout << "You selected item 5.";
            break;
        case 6:
            cout << "You selected item 6.";
            break;
        case 7:
            cout << "You selected item 7.";
            break;
    }

}
