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
        if (book[i].isEmpty() == 1) {
            cout << "Enter the book title: ";
            cin.ignore();
            cin.getline(book[i].bookTitle, 51);
            cout << "Enter the ISBN: ";
            cin.getline(book[i].isbn, 14);
            cout << "Enter the author: ";
            cin.getline(book[i].author, 31);
            cout << "Enter the publisher: ";
            cin.getline(book[i].publisher, 31);
            cout << "Enter the date added: ";
            cin.getline(book[i].dateAdded, 11);
            cout << "Enter the quantity on hand: ";
            cin >> book[i].qtyOnHand;
            cout << "Enter the wholesale cost: ";
            cin >> book[i].wholesale;
            cout << "Enter the retail price: ";
            cin >> book[i].retail;
            strUpper(book[i].bookTitle);
            cout << "Added book " << book[i].bookTitle << " to inventory.\n";
            //syncing the file and the array
            fstream invFile("inventory.dat", ios::out | ios::binary);
            for (int i = 0; i < SIZE; i++) {
                invFile.seekg(i * sizeof(book[i]));
                invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
            }
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
        if (strstr(book[i].bookTitle, searchBook)) {
            cout << "Possible match found: " << book[i].bookTitle << endl;
            cout << "Is this correct? (y/n): ";
            char choice;
            cin >> choice;
            while(choice != 'y' && choice != 'n') {
                cout << "Invalid input. Please try again.\n";
                cout << "Is this correct? (y/n): ";
                cin >> choice;
            }
            if (choice == 'y'){
                bookInfo(book[i].isbn, book[i].bookTitle, book[i].author, book[i].publisher, book[i].dateAdded, book[i].qtyOnHand, book[i].wholesale, book[i].retail, true);
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
    strUpper(editBook);
    //for loop to search the arrays for the book to edit
    for (int i = 0; i < SIZE; i++) {
        if (strstr(book[i].bookTitle, editBook)) {
            cout << "Possible match found: " << book[i].bookTitle << endl;
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
                bookInfo(book[i].isbn, book[i].bookTitle, book[i].author, book[i].publisher, book[i].dateAdded, book[i].qtyOnHand, book[i].wholesale, book[i].retail, true);
                cout << "Which field do you want to edit?\n";
                cout << "1.  Book Title\n2.  ISBN\n3.  Author\n4.  Publisher\n5.  Date Added\n6.  Quantity On Hand\n7.  Wholesale Cost\n8.  Retail Price\n9.  Cancel\n\nEnter your choice: ";
                cin >> choice;
                cin.ignore();
                //switch statement to edit the book info
                switch (choice) {
                    case 1:
                        cout << "Enter the new book title: ";
                        cin.getline(book[i].bookTitle, 51);
                        break;
                    case 2:
                        cout << "Enter the new ISBN: ";
                        cin.getline(book[i].isbn, 14);
                        break;
                    case 3:
                        cout << "Enter the new author: ";
                        cin.getline(book[i].author, 31);
                        break;
                    case 4:
                        cout << "Enter the new publisher: ";
                        cin.getline(book[i].publisher, 31);
                        break;
                    case 5:
                        cout << "Enter the new date added: ";
                        cin.getline(book[i].dateAdded, 11);
                        break;
                    case 6:
                        cout << "Enter the new quantity on hand: ";
                        cin >> book[i].qtyOnHand;
                        break;
                    case 7:
                        cout << "Enter the new wholesale cost: ";
                        cin >> book[i].wholesale;
                        break;
                    case 8:
                        cout << "Enter the new retail price: ";
                        cin >> book[i].retail;
                        break;
                    case 9:
                        cout << "Canceled.\n";
                        return;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
            cout << "Book " << book[i].bookTitle << " has been edited.\n";
            //syncing the file and the array
            fstream invFile("inventory.dat", ios::out | ios::binary);
            for (int i = 0; i < SIZE; i++) {
                invFile.seekg(i * sizeof(book[i]));
                invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
            }
            return;
            }
        }
    }
    cout << "Book not found.\n";
}

//deletes book from the inventory
void deleteBook() {
    char deleteBook[51];
    cout << "What book do you want to delete? ";
    cin.ignore();
    cin.getline(deleteBook, 51);
    strUpper(deleteBook);
    //for loop to search the arrays for the book to delete
    for (int i = 0; i < SIZE; i++) {
        if (strstr(book[i].bookTitle, deleteBook)) {
            cout << "Possible match found: " << book[i].bookTitle << endl;
            cout << "Is this correct? (y/n): ";
            char cont;
            cin >> cont;
            while(cont != 'y' && cont != 'n') {
                cout << "Invalid input. Please try again.\n";
                cout << "Is this correct? (y/n): ";
                cin >> cont;
            }
            if (cont == 'y'){
                book[i].removeBook();
                //syncing the file and the array
                fstream invFile("inventory.dat", ios::out | ios::binary);
                for (int i = 0; i < SIZE; i++) {
                    invFile.seekg(i * sizeof(book[i]));
                    invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
                }
                cout << "Book " << book[i].bookTitle << " has been deleted.\n";
                return;
            }
        }
    }
    cout << "Book not found.\n";
}