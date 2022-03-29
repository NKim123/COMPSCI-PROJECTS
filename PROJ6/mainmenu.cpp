
//including the other functions
#include "cashier.h"
#include "bookinfo.h"
#include "reports.h"
#include "invmenu.h"
#include "mainmenu.h"

using namespace std;

const int SIZE = 20;

//creating arrays for the book info
char bookTitle[SIZE][51];
char isbn[SIZE][14];
char author[SIZE][31];
char publisher[SIZE][31];
char dateAdded[SIZE][11];
int qtyOnHand[SIZE];
double wholesale[SIZE];
double retail[SIZE];

int main(){
    printMenu();
}

void printMenu(){
    
    //declaring choice variable
    int choice = 0;
    while(choice != 4) {
        //printing the menu
        cout << endl;
        cout << right << setw(20) << "\nSerendipity Booksellers\n" << setw(17) << "Main menu\n\n"; 
        cout << left << "1. Cashier Module" << endl;
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
                cashier();
                break;
            case 2:
                invMenu();
                break;
            case 3:
                report();
                break;
            case 4:
                cout << "\nThank you for using Serendipity Booksellers.\n";
                break;
        }
    }

}