#include <iostream>
#include <iomanip>
using namespace std;
void printInvMenu();

int main() {
    printInvMenu();
}

void printInvMenu() {

    //declaring choice variable
    int choice = 0;
    while (choice != 5){

        //printing the inventory menu
        cout << "\n  Serendipity Booksellers\n    Inventory Database\n\n";
        cout << "1.  Look Up a Book\n2.  Add a Book\n3.  Edit a book's Record\n4.  Delete a Book\n5.  Return to the Main Menu\n\n";
        cout << "Enter your choice: ";
        
        //getting the user's choice with input validation
        do {
            cin >> choice;
            if (choice < 1 || choice > 5) {
                cout << "Invalid choice. (Please enter a number 1 - 5)\n";
                cout << "Enter your choice: ";
            }
        } while (choice < 1 || choice > 5);

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
        }
    }

}