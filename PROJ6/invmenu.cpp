#include "invmenu.h"
#include "bookinfo.h"
#include "strupper.h"

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
        if (strcmp(bookTitle[i], "") == 0) {
            cout << "Enter the book title: ";
            cin.ignore();
            cin.getline(bookTitle[i], 51);
            cout << "Enter the ISBN: ";
            cin.getline(isbn[i], 14);
            cout << "Enter the author: ";
            cin.getline(author[i], 31);
            cout << "Enter the publisher: ";
            cin.getline(publisher[i], 31);
            cout << "Enter the date added: ";
            cin.getline(dateAdded[i], 11);
            cout << "Enter the quantity on hand: ";
            cin >> qtyOnHand[i];
            cout << "Enter the wholesale cost: ";
            cin >> wholesale[i];
            cout << "Enter the retail price: ";
            cin >> retail[i];
            strUpper(bookTitle[i]);
            cout << "Added book " << bookTitle[i] << " to inventory.\n";
            return;
        }
    }    
}

//finds book in the inventory
void lookUpBook(){
    char searchBook[51];
    cout << "What book do you want to search for? ";
    cin.ignore();
    cin.getline(searchBook, 51);
    strUpper(searchBook);
    //for loop to search the arrays for the book
    for (int i = 0; i < SIZE; i++) {
        if (strstr(bookTitle[i], searchBook)) {
            cout << "Possible match found: " << bookTitle[i] << endl;
            cout << "Is this correct? (y/n): ";
            char choice;
            cin >> choice;
            while(choice != 'y' && choice != 'n') {
                cout << "Invalid input. Please try again.\n";
                cout << "Is this correct? (y/n): ";
                cin >> choice;
            }
            if (choice == 'y'){
                bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i], true);
                return;
            }
            if (i == SIZE - 1) {
                cout << "The book you searched for does not exist.\n";
            }
        }
    }
    cout << "Book not found.\n";
}

//edits book in the inventory
void editBook() {
    char editBook[51];
    int choice = 0;
    cout << "What book do you want to edit? ";
    cin.ignore();
    cin.getline(editBook, 51);
    //for loop to search the arrays for the book to edit
    for (int i = 0; i < SIZE; i++) {
        if (strstr(bookTitle[i], editBook)) {
            cout << "Possible match found: " << bookTitle[i] << endl;
            cout << "Is this correct? (y/n): ";
            char cont;
            cin >> cont;
            while(cont != 'y' && cont != 'n') {
                cout << "Invalid input. Please try again.\n";
                cout << "Is this correct? (y/n): ";
                cin >> cont;
            }
            if(cont == 'y'){
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
                        cin.getline(bookTitle[i], 51);
                        break;
                    case 2:
                        cout << "Enter the new ISBN: ";
                        cin.getline(isbn[i], 14);
                        break;
                    case 3:
                        cout << "Enter the new author: ";
                        cin.getline(author[i], 31);
                        break;
                    case 4:
                        cout << "Enter the new publisher: ";
                        cin.getline(publisher[i], 31);
                        break;
                    case 5:
                        cout << "Enter the new date added: ";
                        cin.getline(dateAdded[i], 11);
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
            } else if(cont == 'n') {
                
            }
            cout << "Book " << bookTitle[i] << " has been edited.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

//deletes book from the inventory
void deleteBook() {
    char deleteBook[51];
    cout << "What book do you want to delete?\n";
    cin.ignore();
    cin.getline(deleteBook, 51);
    //for loop to search the arrays for the book to delete
    for (int i = 0; i < SIZE; i++) {
        if (strstr(bookTitle[i], deleteBook)) {
            strcpy(bookTitle[i], "");
            strcpy(isbn[i], "");
            strcpy(author[i], "");
            strcpy(publisher[i], "");
            strcpy(dateAdded[i], "");
            qtyOnHand[i] = 0;
            wholesale[i] = 0;
            retail[i] = 0;
            cout << "Book " << bookTitle[i] << " has been deleted.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}