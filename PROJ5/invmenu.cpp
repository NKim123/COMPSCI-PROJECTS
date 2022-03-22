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

//adds book to the inventory
void addBook() {
    //for loop to search the arrays for an empty slot
    for (int i = 0; i < SIZE; i++) {
        if (bookTitle[i] == ""){
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, bookTitle[i]);
            cout << "Enter the ISBN: ";
            getline(cin, isbn[i]);
            cout << "Enter the author: ";
            getline(cin, author[i]);
            cout << "Enter the publisher: ";
            getline(cin, publisher[i]);
            cout << "Enter the date added: ";
            getline(cin, dateAdded[i]);
            cout << "Enter the quantity on hand: ";
            cin >> qtyOnHand[i];
            cout << "Enter the wholesale cost: ";
            cin >> wholesale[i];
            cout << "Enter the retail price: ";
            cin >> retail[i];
            cout << "Added book " << bookTitle[i] << " to inventory.\n";
            return;
        }
    }    
}

//finds book in the inventory
void lookUpBook(){
    string searchBook = "";
    cout << "What book do you want to search for? ";
    cin.ignore();
    getline(cin, searchBook);
    //for loop to search the arrays for the book
    for (int i = 0; i < SIZE; i++) {
        if (searchBook == bookTitle[i]) {
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i], true);
            return;
        }
    }
    cout << "Book not found.\n";
}

//edits book in the inventory
void editBook() {
    string editBook = "";
    int choice = 0;
    cout << "What book do you want to edit? ";
    cin.ignore();
    getline(cin, editBook);
    //for loop to search the arrays for the book to edit
    for (int i = 0; i < SIZE; i++) {
        if (editBook == bookTitle[i]) {
            //printing the book info
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i], true);
            cout << "Which field do you want to edit?\n";
            cout << "1.  Book Title\n2.  ISBN\n3.  Author\n4.  Publisher\n5.  Date Added\n6.  Quantity On Hand\n7.  Wholesale Cost\n8.  Retail Price\n9.  Cancel\n\nEnter your choice: ";
            cin >> choice;
            cin.ignore();
            //switch statement to edit the book info
            switch (choice) {
                case 1:
                    cout << "Enter the new book title: ";
                    getline(cin, bookTitle[i]);
                    break;
                case 2:
                    cout << "Enter the new ISBN: ";
                    getline(cin, isbn[i]);
                    break;
                case 3:
                    cout << "Enter the new author: ";
                    getline(cin, author[i]);
                    break;
                case 4:
                    cout << "Enter the new publisher: ";
                    getline(cin, publisher[i]);
                    break;
                case 5:
                    cout << "Enter the new date added: ";
                    getline(cin, dateAdded[i]);
                    break;
                case 6:
                    cout << "Enter the new quantity on hand: ";
                    cin >> qtyOnHand[i];
                    break;
                case 7:
                    cout << "Enter the new wholesale cost: ";
                    cin >> wholesale[i];
                    break;
                case 8:
                    cout << "Enter the new retail price: ";
                    cin >> retail[i];
                    break;
                case 9:
                    cout << "Canceled.\n";
                    return;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            cout << "Book " << bookTitle[i] << " has been edited.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

//deletes book from the inventory
void deleteBook() {
    string deleteBook = "";
    cout << "What book do you want to delete?\n";
    cin.ignore();
    getline(cin, deleteBook);
    //for loop to search the arrays for the book to delete
    for (int i = 0; i < SIZE; i++) {
        if (deleteBook == bookTitle[i]) {
            bookTitle[i] = "";
            isbn[i] = "";
            author[i] = "";
            publisher[i] = "";
            dateAdded[i] = "";
            qtyOnHand[i] = 0;
            wholesale[i] = 0;
            retail[i] = 0;
            cout << "Book " << bookTitle[i] << " has been deleted.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}