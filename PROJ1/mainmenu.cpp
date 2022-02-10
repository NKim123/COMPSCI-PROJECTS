#include <iostream>
#include <iomanip>
using namespace std;
void printMenu();

int main(){
    printMenu();
}

void printMenu(){

    //declaring choice variable
    int choice = 0;
    
    //printing the menu
    cout << setw(20) << "\nSerendipity Booksellers\n" << setw(17) << "Main menu\n\n"; 
    cout << "1. Cashier Module" << endl;
    cout << "2. Inventory Database Module" << endl;
    cout << "3. Reports Module" << endl;
    cout << "4. Exit\n\n";
    cout << "Enter your choice: ";

    //getting the user's choice
    cin >> choice;
}