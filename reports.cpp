#include <iostream>
#include <iomanip>
using namespace std;
void printReport();

int main(){
    printReport();
}

void printReport(){
    cout << right << setw(20) << "\nSerendipity Booksellers\n" << setw(16) << "Reports\n\n";
    cout << "1.  Inventory Listing\n";
    cout << "2.  Inventory Wholesale Value\n";
    cout << "3.  Inventory Retail Value\n";
    cout << "4.  Listing by Quantity\n";
    cout << "5.  Listing by Cost\n";
    cout << "6.  Listing by Age\n";
    cout << "7.  Return to Main Menu\n\n";
    cout << "Enter Your Choice: ";
}
