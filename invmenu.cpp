#include <iostream>
#include <iomanip>
using namespace std;
void printInvMenu();

int main() {
    printInvMenu();
}

void printInvMenu() {
    //declaring choice variable
    int choice = 0;

    //printing the inventory menu
    cout << "\n  Serendipity Booksellers\n    Inventory Database\n\n";
    cout << "1.  Look Up a Book\n2.  Add a Book\n3.  Edit a book's Record\n4.  Delete a Book\n5.  Return to the Main Menu\n\n";
    cout << "Enter your choice: ";
    
    //getting the user's choice
    cin >> choice;
}