#include "cashier.h"
#include "invmenu.h"
#include "soldbook.h"
#include "inventorybook.h"

const int SIZE = 20;

//declaration of cashier function
void cashier(){
    //declaring variables
    char date[SIZE][11], isbn[SIZE][14], title[SIZE][51];
    float price[10], total[10], Total = 0, tax = 0;
    int quantity[10], quant;
    string choice = "";

    //big loop to allow multiple transactions
    do {
        
        //index to keep track of titles
        int index = 0; 

        cout << "Serendipity Booksellers\n" << "  Cashier Module\n\n";
        cout << "Enter the date: ";
        cin.ignore();
        cin.getline(date[index], 11);
        
        //Asking how many books are being sold
        cout << "How many books are you buying today? ";
        cin >> quant;
        cin.ignore();
        //creating dynamically allocated array of sold books
        SoldBook *bookList = new SoldBook[quant];
        //looping through to add books to the sold book array
        for (int i = 0; i < quant; i++) {
            string a = "y";
            do {
                cout << "Enter the ISBN: ";
                cin.getline(isbn[index], 14);
                //searching for isbn inside global isbn array
                for (int i = 0; i < SIZE; i++) {
                    if (strcmp(isbn[index], book[i].getIsbn()) == 0) {
                        strcpy(title[index], book[i].getTitle());
                        price[index] = book[i].getRetail();
                        cout << "found book: " << title[index] << endl; 
                        //checking quantity
                        cout << "Enter the quantity: ";
                        cin >> quantity[index];
                        while (quantity[index] > book[i].getQtyOnHand()) {
                            cout << "Not enough quantity on hand. Please enter new quantity: \n";
                            cin >> quantity[index];
                        }
                        book[i].setQtyOnHand(book[i].getQtyOnHand() - quantity[index]);
                        cout << "Added book" << endl;
                        while(getchar() != '\n');
                        total[index] = (price[index] * quantity[index]);
                        a = "n";
                        break;
                    }
                    if (i == SIZE-1) {
                        cout << "Book not found, try again? (y/n): ";
                        cin >> a;
                        //clearing cin
                        while (getchar() != '\n');
                        if (a == "n") {
                            break;
                        }
                    }
                    bookList[i].setIsbn(isbn[index]);
                    bookList[i].setTitle(title[index]);
                    bookList[i].setRetail(book[i].getRetail());
                    bookList[i].setWholesale(book[i].getWholesale());
                    bookList[i].setQtyOnHand(book[i].getQtyOnHand());
                    bookList[i].setQtySold(quantity[index]);
                }
            } while (a == "y");
        }

        //printing the receipt
        cout << "\nSeredipity Book Sellers\n\n";
        cout << "Date: " << date[0] << "\n\n";

        //calculating total
        for (int i = 0; i < quant; i++) {
            bookList[i].addTotal(total[i] + bookList[i].getTax());
        }

        //list of items
        cout << left << setw(5) << "QTY" << setw(15) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "_________________________________________________________________\n";
        //loop to print the different titles
        for (int i = 0; i < quant; i++) {
            cout << left << setw(5) << bookList[i].getQtyOnHand() << setw(15) << bookList[i].getIsbn() << setw(25) << bookList[i].getTitle() << setw(10) << bookList[i].getRetail() << setw(10) << bookList[i].setSubtotal() << endl;
        }
        cout << "          " << setw(45) << "Subtotal" << setw(2) << "$" << setw(8) << bookList[1].setSubtotal()/1.06 << endl;
        cout << "          " << setw(45) << "Tax" << setw(2) << "$" << setw(8) << bookList[1].getTax() << endl;
        cout << "          " << setw(45) << "Total" << setw(2) << "$" << setw(8) << bookList[1].getTotal() << endl << endl;
        cout << left << "Thank You for Shopping at Seredipity!\n\n";

        //prompting user for choice
        cout << "Would you like to process another transaction? (y/n): ";
        getline(cin, choice);
        
        while (choice != "y" && choice != "n"){
            cout << "Please enter a valid choice. (y/n): ";
            getline(cin, choice);
        }
        
    } while (choice == "y");

}