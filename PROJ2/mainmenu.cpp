#include <iostream>
#include <iomanip>
using namespace std;
void printMenu();

int main(){
    printMenu();
}

void printMenu(){
    
    //declaring choice variable
    int choice = 0;
    while(choice != 4) {
        //printing the menu
        cout << setw(20) << "\nSerendipity Booksellers\n" << setw(17) << "Main menu\n\n"; 
        cout << "1. Cashier Module" << endl;
        cout << "2. Inventory Database Module" << endl;
        cout << "3. Reports Module" << endl;
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";

        //getting the user's choice with input validation
        do {
            cin >> choice;
            if (choice < 1 || choice > 4) {
                cout << "Invalid choice. (Please enter a number 1 - 4)\n";
                cout << "Enter your choice: ";
            }
        } while (choice < 1 || choice > 4);

        //switch statment to print the user's choice
        switch (choice) {
            case 1: 
                cout << "You selected item 1." << endl;
                break;
            case 2:
                cout << "You selected item 2." << endl;
                break;
            case 3:
                cout << "You selected item 3." << endl;
                break;
            case 4:
                cout << "You selected item 4." << endl;
                break;
        }
    }

}