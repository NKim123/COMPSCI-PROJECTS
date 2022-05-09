#include "reports.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "mainmenu.h"

const int SIZE = 20;
void report(){
    
    //declaring choice variable
    int choice = 0;

    while (choice != 7) {
    
        //printing the report
        cout << right << setw(20) << "\nSerendipity Booksellers\n" << setw(16) << "Reports\n\n";
        cout << "1.  Inventory Listing\n";
        cout << "2.  Inventory Wholesale Value\n";
        cout << "3.  Inventory Retail Value\n";
        cout << "4.  Listing by Quantity\n";
        cout << "5.  Listing by Cost\n";
        cout << "6.  Listing by Age\n";
        cout << "7.  Return to Main Menu\n\n";
        cout << "Enter Your Choice: ";

        cin >> choice;
    
        //getting the user's choice with input validation
        while (choice < 1 || choice > 7){
            if (choice < 1 || choice > 7) {
                cout << "Invalid choice. (Please enter a number 1 - 7)\n";
                cout << "Enter your choice: ";
            }
        } 

        //switch statment to print the user's choice
        switch(choice) {
            case 1:
                repListing();
                break;
            case 2:
                repWholesale();
                break;
            case 3:
                repRetail();
                break;
            case 4:
                repQty();
                break;
            case 5:
                repCost();
                break;
            case 6:
                repAge();
                break;
            case 7:
                printMenu();
                return;
        }
    }
}

//stub functions
void repListing() {
    cout << "You selected a listing report.\n";
    
    for (int i = 0; i < SIZE; i ++) {
        bookInfo(book[i].getIsbn(), book[i].getTitle(), book[i].getAuthor(), book[i].getPublisher(), book[i].getDateAdded(), book[i].getQtyOnHand(), book[i].getWholesale(), book[i].getRetail(), true);
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

void repWholesale() {
    cout << "You selected a wholesale report.\n";
    double total = 0.0;
    for (int i = 0; i < SIZE; i ++) {
        cout << "Title: " << book[i].getTitle() << endl;
        cout << "ISBN: " << book[i].getIsbn() << endl;
        cout << "Quantity On hand: " << book[i].getQtyOnHand() << endl;
        cout << "Wholesale Cost: " << book[i].getWholesale() << endl;
        total += book[i].getWholesale() * book[i].getQtyOnHand();
        cout << "\n\n";
    }
    cout << "Total Wholesale Value: " << total << endl;
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

void repRetail() {
    cout << "You selected retail report.\n";
    double total = 0;
    for (int i = 0; i < SIZE; i ++){
        if (strcmp(book[i].getTitle(), "") != 0) {
            cout << "Title: " << book[i].getTitle() << endl;
            cout << "ISBN: " << book[i].getIsbn() << endl;
            cout << "Quantity On hand: " << book[i].getQtyOnHand() << endl;
            cout << "Retail Price: " << book[i].getRetail() << endl;
            total += book[i].getRetail() * book[i].getQtyOnHand();
            cout << "\n\n";
        }
    }
    cout << "Total Retail Value: " << total << endl;
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

//sorts the array in decending order by quantity
void repQty() {
    cout << "You selected a sorted quantity report.\n";
    InvBook *qtyPtr[SIZE];
    int idPtr[SIZE];

    for (int i = 0; i < SIZE; i ++) {
        qtyPtr[i] = &book[i];
        idPtr[i] = i;
    }
    
    //selection sorting the array
    int i, j, max_idx; 

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if ((*qtyPtr[j]).getQtyOnHand() > (*qtyPtr[max_idx]).getQtyOnHand()) 
            max_idx = j; 

        //swapping the values
        InvBook *temp = qtyPtr[max_idx];
        qtyPtr[max_idx] = qtyPtr[i];
        qtyPtr[i] = temp;
        int temp2 = idPtr[max_idx];
        idPtr[max_idx] = idPtr[i];
        idPtr[i] = temp2;
    } 

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        if (strcmp(book[idPtr[i]].getTitle(), "") != 0) {
            cout << "Title: " << book[idPtr[i]].getTitle() << endl;
            cout << "ISBN: " << book[idPtr[i]].getIsbn() << endl;
            cout << "Quantity On hand: " << book[idPtr[i]].getQtyOnHand() << endl;
            cout << "\n\n";
        }
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

//sorts the array in decending order by cost
void repCost() {
    cout << "You selected a sorted cost report.\n";
    InvBook *costPtr[SIZE];
    int idPtr[SIZE];
    for(int i = 0; i < SIZE; i ++) {
        costPtr[i] = &book[i];
        idPtr[i] = i;
    }

    //selection sorting the array
    int i, j, max_idx;
    
    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if ((*costPtr[j]).getWholesale() > (*costPtr[max_idx]).getWholesale()) 
            max_idx = j; 

        //swapping the values
        InvBook *temp = costPtr[max_idx];
        costPtr[max_idx] = costPtr[i];
        costPtr[i] = temp;
    }

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        if (strcmp(book[idPtr[i]].getTitle(), "") != 0) {
            cout << "Title: " << book[idPtr[i]].getTitle() << endl;
            cout << "ISBN: " << book[idPtr[i]].getIsbn() << endl;
            cout << "Wholesale Cost: " << book[idPtr[i]].getWholesale() << endl;
            cout << "\n\n";
        }
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }

}

//sorts the array in decending order by age
void repAge() {
    cout << "You selected a sorted age report.\n";
    InvBook *agePtr[SIZE];
    int idPtr[SIZE];
    for (int i = 0; i < SIZE-1; i ++) {   //make an array of pointers to the dateAdded array
        agePtr[i] = &book[i];
        idPtr[i] = i;
    }

    //selection sorting the array
    int i, j, max_idx;

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE-1; j++) {

            if (strcmp((*agePtr[j]).getDateAdded(), ((*agePtr[max_idx]).getDateAdded())) >= 0){
                max_idx = j; 
            }
        }

        //swapping the values of max and i
        InvBook *temp = agePtr[max_idx];
        agePtr[max_idx] = agePtr[i];
        agePtr[i] = temp;
        int tem = idPtr[max_idx];
        idPtr[max_idx] = idPtr[i];
        idPtr[i] = tem;  
    }

    //printing the sorted array
    for (int i = 0; i < SIZE-1; i ++) {
        if (strcmp((*agePtr[idPtr[i]]).getDateAdded(), "") != 0) {
            cout << "Title: " << book[idPtr[i]].getTitle() << endl;
            cout << "ISBN: " << book[idPtr[i]].getIsbn() << endl;
            cout << "Date Added: " << book[idPtr[i]].getDateAdded() << endl;
            cout << "\n\n";
        }
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}