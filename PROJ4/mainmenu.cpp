#include <iomanip>
#include <iostream>

//including the other functions
#include "cashier.h"
#include "bookinfo.h"
#include "reports.h"
#include "invmenu.h"

using namespace std;

const int SIZE = 20;

//creating global arrays for the book info
string bookTitle[SIZE];
string isbn[SIZE];
string author[SIZE];
string publisher[SIZE];
string dateAdded[SIZE];
int qtyOnHand[SIZE];
double wholesale[SIZE];
double retail[SIZE];

void printMenu();

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