#include <iostream>
#include <iomanip>
using namespace std;
void printCashier();

int main(){
    printCashier();
}

void printCashier(){
    cout << "\nSeredipity Book Sellers\n\n";
    cout << "Date: \n\n";
    //list of items
    cout << left << setw(5) << "QTY" << setw(15) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << "_________________________________________________________________\n";
    cout << left << setw(5) << "" << setw(15) << "" << setw(25) << "" << setw(2) << "$" << setw(8) << "100.00" << setw(2) << "$" << setw(8) << "100.00" << endl << endl;
    cout << "          " << setw(45) << "Subtotal" << setw(2) << "$" << setw(8) << "" << endl;
    cout << "          " << setw(45) << "Tax" << setw(2) << "$" << setw(8) << "" << endl;
    cout << "          " << setw(45) << "Total" << setw(2) << "$" << setw(8) << "" << endl << endl;
    cout << left << "Thank You for Shopping at Seredipity!\n\n";

}