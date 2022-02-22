#include "invmenu.h"

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
    cout << "You selected Look Up Book.";
}

void addBook() {
    cout << "You selected Add Book.";
}

void editBook() {
    cout << "You selected Edit Book.";
}

void deleteBook() {
    cout << "You selected Delete Book.";
}