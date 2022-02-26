#include "invmenu.h"
#include "bookinfo.h"

const int SIZE = 20;

void invMenu() {

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
                lookUpBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                cout << "You selected item 5.";
                break;
        }
    }

}

//stub functions
void lookUpBook(){
    string searchBook = "";
    cout << "What book do you want to search for?\n";
    getline(cin, searchBook);
    for (int i = 0; i < SIZE; i++) {
        if (searchBook == bookTitle[i]) {
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
        }
    }

}

void addBook() {
    for (int i = 0; i < SIZE; i++) {
        if (bookTitle[i] == ""){
            cout << "Enter the book title: ";
            getline(cin, bookTitle[i]);
            cout << "Enter the ISBN: ";
            getline(cin, isbn[i]);
            cout << "Enter the author: ";
            getline(cin, author[i]);
            cout << "Enter the publisher: ";
            getline(cin, publisher[i]);
            cout << "Enter the date added: ";
            getline(cin, dateAdded[i]);
            cin.ignore();
            cout << "Enter the quantity on hand: ";
            cin >> qtyOnHand[i];
            cout << "Enter the wholesale cost: ";
            cin >> wholesale[i];
            cout << "Enter the retail price: ";
            cin >> retail[i];

        }
    }    
}

void editBook() {
    cout << "You selected Edit Book.";
}

void deleteBook() {
    cout << "You selected Delete Book.";
}