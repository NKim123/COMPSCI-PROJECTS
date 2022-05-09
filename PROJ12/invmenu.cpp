#include "invmenu.h"
#include "bookinfo.h"
#include "strupper.h"
#include "inVal.h"

const int SIZE = 20;

void invMenu() {

    //declaring choice variable
    inVal input;
    while (input.showInputInt() != 5){

        //printing the inventory menu
        cout << "\n  Serendipity Booksellers\n    Inventory Database\n\n";
        cout << "1.  Look Up a Book\n2.  Add a Book\n3.  Edit a book's Record\n4.  Delete a Book\n5.  Return to the Main Menu\n\n";
        cout << "Enter your choice: ";
        
        //getting the user's choice with input validation
        input.inValInt(1, 5);

        //switch statment to print the user's choice
        switch(input.showInputInt()) {
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
            string inputBuffStr = "";
            int inputBuffInt = 0;
            double inputBuffDouble = 0;
            //getting title
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, inputBuffStr);
            book[i].setTitle(inputBuffStr);
            //getting ISBN
            cout << "Enter the ISBN: ";
            getline(cin, inputBuffStr);
            book[i].setIsbn(inputBuffStr);
            //getting author
            cout << "Enter the author: ";
            getline(cin, inputBuffStr);
            book[i].setAuthor(inputBuffStr);
            //getting publisher
            cout << "Enter the publisher: ";
            getline(cin, inputBuffStr);
            book[i].setPublisher(inputBuffStr);
            //getting date added
            cout << "Enter the date added: ";
            getline(cin, inputBuffStr);
            book[i].setDateAdded(inputBuffStr);
            //getting quantity on hand
            cout << "Enter the quantity on hand: ";
            cin >> inputBuffInt;
            book[i].setQtyOnHand(inputBuffInt);
            //getting wholesale cost
            cout << "Enter the wholesale cost: ";
            cin >> inputBuffDouble;
            book[i].setWholesale(inputBuffDouble);
            //getting retail price
            cout << "Enter the retail price: ";
            cin >> inputBuffDouble;
            book[i].setRetail(inputBuffDouble);
            //setting the title to uppercase
            char* tempC = book[i].getTitle();
            strUpper(tempC);
            book[i].setTitle(tempC);
            cout << "Added book " << book[i].getTitle() << " to inventory.\n";
            //syncing the file and the array
            fstream invFile("inventory.txt", ios::out | ios::binary);
            for (int i = 0; i < SIZE; i++) {
                invFile.seekp(i * sizeof(book[i]));
                invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
            }
            invFile.close();
            return;
        }
    }    
}

//finds book in the inventory
void lookUpBook(){
    char searchBook[51];
    inVal input;
    cout << "What book do you want to search for? ";
    cin.ignore();
    cin.getline(searchBook, 51);
    strUpper(searchBook);
    //for loop to search the arrays for the book
    for (int i = 0; i < SIZE; i++) {
        if (book[i].bookMatch(searchBook)==1) {
            cout << "Possible match found: " << book[i].getTitle() << endl;
            cout << "Is this correct? (y/n): ";
            if (input.inValString("y", "n") == 1 && input.showInputString() == "y") {
                bookInfo(book[i].getIsbn(), book[i].getTitle(), book[i].getAuthor(), book[i].getPublisher(), book[i].getDateAdded(), book[i].getQtyOnHand(), book[i].getWholesale(), book[i].getRetail(), true);
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
    inVal input;
    cout << "What book do you want to edit? ";
    cin.ignore();
    cin.getline(editBook, 51);
    strUpper(editBook);
    //for loop to search the arrays for the book to edit
    for (int i = 0; i < SIZE; i++) {
        if (book[i].bookMatch(editBook) == 1) {
            cout << "Possible match found: " << book[i].getTitle() << endl;
            cout << "Is this correct? (y/n): ";
            //input validation for the user's choice
            if(input.inValString("y", "n") && input.showInputString() == "y") {
                //printing the book info
                bookInfo(book[i].getIsbn(), book[i].getTitle(), book[i].getAuthor(), book[i].getPublisher(), book[i].getDateAdded(), book[i].getQtyOnHand(), book[i].getWholesale(), book[i].getRetail(), true);
                cout << "Which field do you want to edit?\n";
                cout << "1.  Book Title\n2.  ISBN\n3.  Author\n4.  Publisher\n5.  Date Added\n6.  Quantity On Hand\n7.  Wholesale Cost\n8.  Retail Price\n9.  Cancel\n\nEnter your choice: ";
                //getting input
                input.clear();
                input.inValInt(1, 9);
                cin.ignore();
                //temporary variables to hold the new values
                string inputBuffStr = "";
                int inputBuffInt = 0;
                double inputBuffDouble = 0;
                //switch statement to edit the book info
                switch (input.showInputInt()) {
                    case 1:
                        cout << "Enter the new book title: ";
                        getline(cin, inputBuffStr);
                        book[i].setTitle(inputBuffStr);
                        break;
                    case 2:
                        cout << "Enter the new ISBN: ";
                        getline(cin, inputBuffStr);
                        book[i].setIsbn(inputBuffStr);
                        break;
                    case 3:
                        cout << "Enter the new author: ";
                        getline(cin, inputBuffStr);
                        book[i].setAuthor(inputBuffStr);
                        break;
                    case 4:
                        cout << "Enter the new publisher: ";
                        getline(cin, inputBuffStr);
                        book[i].setPublisher(inputBuffStr);
                        break;
                    case 5:
                        cout << "Enter the new date added: ";
                        getline(cin, inputBuffStr);
                        book[i].setDateAdded(inputBuffStr);
                        break;
                    case 6:
                        cout << "Enter the new quantity on hand: ";
                        cin >> inputBuffInt;
                        book[i].setQtyOnHand(inputBuffInt);
                        break;
                    case 7:
                        cout << "Enter the new wholesale cost: ";
                        cin >> inputBuffDouble;
                        book[i].setWholesale(inputBuffDouble);
                        break;
                    case 8:
                        cout << "Enter the new retail price: ";
                        cin >> inputBuffDouble;
                        book[i].setRetail(inputBuffDouble); 
                        break;
                    case 9:
                        cout << "Canceled.\n";
                        return;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
            cout << "Book " << book[i].getTitle() << " has been edited.\n";
            //syncing the file and the array
            fstream invFile("inventory.txt", ios::out | ios::binary);
            for (int i = 0; i < SIZE; i++) {
                invFile.seekp(i * sizeof(book[i]));
                invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
            }
            invFile.close();
            return;
            }
        }
    }
    cout << "Book not found.\n";
}

//deletes book from the inventory
void deleteBook() {
    char deleteBook[51];
    inVal input;
    cout << "What book do you want to delete? ";
    cin.ignore();
    cin.getline(deleteBook, 51);
    strUpper(deleteBook);
    //for loop to search the array for the book to delete
    for (int i = 0; i < SIZE; i++) {
        if (book[i].bookMatch(deleteBook) == 1) {
            cout << "Possible match found: " << book[i].getTitle() << endl;
            cout << "Is this correct? (y/n): ";
            //get input and validate
            if (input.inValString("y", "n") && input.showInputString() == "y") {
                book[i].removeBook();
                //syncing the file and the array
                fstream invFile("inventory.txt", ios::out | ios::binary);
                for (int i = 0; i < SIZE; i++) {
                    invFile.seekg(i * sizeof(book[i]));
                    invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
                }
                cout << "Book " << book[i].getTitle() << " has been deleted.\n";
                return;
            }
        }
    }
    //syncing the file and the array
    fstream invFile("inventory.txt", ios::out | ios::binary);
    for (int i = 0; i < SIZE; i++) {
        invFile.seekg(i * sizeof(book[i]));
        invFile.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
    }
    invFile.close();
    cout << "Book not found.\n";
}