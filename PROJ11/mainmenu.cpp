
//including the other functions
#include "cashier.h"
#include "bookinfo.h"
#include "reports.h"
#include "invmenu.h"
#include "mainmenu.h"

using namespace std;

const int SIZE = 20;

//creating arrays for the book info
BookData book[SIZE];

//associating the datafile and creating fstream object
fstream invFile;

int main(){
    //if file doesn't exist, create new one
    invFile.open("inventory.txt", ios::in | ios::out | ios::binary);
    if (invFile.fail()) {
        cout << "File does not exist, creating new one.\n";
        invFile.open("inventory.txt", ios::in | ios::binary);
        invFile.close();
        invFile.clear();
        cout << "File created. You must add new data to the file.\n";
        if (invFile.fail()){
            cout << "File creation failed.\n";
            return 1;
        }
        
    } else {
        //for loop to read the file into the book array
        for (int i = 0; i < SIZE; i++) {
            invFile.seekg(i * sizeof(book[i]), ios::beg);
            invFile.read(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));

            if (invFile.eof()) {
                break;
            }
        }
        invFile.close();
    }

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