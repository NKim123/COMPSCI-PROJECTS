#include "cashier.h"
#include "invmenu.h"

const int SIZE = 20;

//declaration of cashier function
void cashier(){
    //declaring variables
    string date[10], isbn[10], title[10];
    float price[10], total[10], Total = 0, tax = 0;
    int quantity[10];
    string choice = "";

    //big loop to allow multiple transactions
    do {
        
        //index to keep track of titles
        int index = 0; 

        cout << "Serendipity Booksellers\n" << "  Cashier Module\n\n";
        cout << "Enter the date: ";
        cin.ignore();
        getline(cin, date[index]);
        
        //smaller loop to allow multiple titles to be added
        while (true) {
            string cont = "";
            string a = "y";
            do {
                //prompting user for input
                cout << "Enter the ISBN: ";
                getline(cin, isbn[index]);

                //searching for isbn inside global isbn array
                for (int i = 0; i < SIZE; i++) {
                    if (isbn[index] == ::isbn[i]) {
                        title[index] = bookTitle[i];
                        price[index] = retail[i];
                        cout << "found book: " << title[index] << endl;
                        //checking quantity
                        cout << "Enter the quantity: ";
                        cin >> quantity[index];
                        while (quantity[index] > qtyOnHand[i]) {
                            cout << "Not enough quantity on hand. Please enter new quantity: \n";
                            cin >> quantity[index];
                        }
                        cout << "Added book" << endl;
                        total[index] = (price[index] * quantity[index]);
                        a = "n";
                        break;
                    }
                }
                
                if (title[index] == "") {
                    cout << "Book not found, try again? (y/n): ";
                    cin >> a;
                    //clearing cin
                    while (getchar() != '\n');

                    if (a == "n") {
                        break;
                    }
                }

            } while (a == "y");

            //input validation for the continue prompt
            while (cont != "y" && cont != "n") {
                cout << "Do you want to add another title? (y/n): ";
                cin >> cont;
                if (cont != "n" && cont != "y") {
                    cout << "Invalid input. Please try again.\n";
                }
            }

            //clearing cin
            while ((getchar()) != '\n');
            
            if (cont == "n") {
                break;
            } else {
                index++;
                cout << index << endl << endl;
            }

        }

        //printing the receipt
        cout << "\nSeredipity Book Sellers\n\n";
        cout << "Date: " << date[0] << "\n\n";

        //calculating total
        for (int i = 0; i < index+1; i++) {
            Total += total[i];
        }
        tax = Total * 0.06;
        Total = Total + tax;

        //list of items
        cout << left << setw(5) << "QTY" << setw(15) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "_________________________________________________________________\n";
        //loop to print the different titles
        for (int i = 0; i < index+1; i++) {
            cout << left << setw(5) << quantity[i] << setw(15) << isbn[i] << setw(25) << title[i] << setw(10) << price[i] << setw(10) << total[i] << endl;
        }
        cout << "          " << setw(45) << "Subtotal" << setw(2) << "$" << setw(8) << Total/1.06 << endl;
        cout << "          " << setw(45) << "Tax" << setw(2) << "$" << setw(8) << tax << endl;
        cout << "          " << setw(45) << "Total" << setw(2) << "$" << setw(8) << Total << endl << endl;
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