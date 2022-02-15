#include <iostream>
#include <iomanip>
using namespace std;
void printCashier();

int main(){
    printCashier();
}

void printCashier(){
    //declaring variables
    string date, isbn, title;
    float price, total, Total, tax;
    int quantity;
    string choice = "";

    do {
        //prompting user for input
        cout << "Serendipity Booksellers\n" << "  Cashier Module\n\n";
        cout << "Enter the date: ";
        getline(cin, date);
        cout << "Enter the ISBN: ";
        getline(cin, isbn);
        cout << "Enter the title: ";
        getline(cin, title);
        cout << "Enter the price: ";
        cin >> price;
        cout << "Enter the quantity: ";
        cin >> quantity;

        //printing the receipt
        cout << "\nSeredipity Book Sellers\n\n";
        cout << "Date: " << date << "\n\n";

        //calculating total
        total = (price * quantity);
        tax = total * 0.06;
        Total = total + tax;

        //list of items
        cout << left << setw(5) << "QTY" << setw(15) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "_________________________________________________________________\n";
        cout << left << setw(5) << quantity << setw(15) << isbn << setw(25) << title << setw(2) << "$" << setw(8) << price << setw(2) << "$" << setw(8) << showpoint << fixed << setprecision(2) << total << endl << endl;
        cout << "          " << setw(45) << "Subtotal" << setw(2) << "$" << setw(8) << total << endl;
        cout << "          " << setw(45) << "Tax" << setw(2) << "$" << setw(8) << tax << endl;
        cout << "          " << setw(45) << "Total" << setw(2) << "$" << setw(8) << Total << endl << endl;
        cout << left << "Thank You for Shopping at Seredipity!\n\n";

        //prompting user for another transaction
        cout << "Would you like to process another transaction? (y/n): ";
        cin >> choice;
        
    } while (choice == "y");

}