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
        /*
        //getting the user's choice with input validation
        while (choice < 1 || choice > 7){
            if (choice < 1 || choice > 7) {
                cout << "Invalid choice. (Please enter a number 1 - 7)\n";
                cout << "Enter your choice: ";
            }
        } */

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
        bookInfo(book[i].isbn, book[i].bookTitle, book[i].author, book[i].publisher, book[i].dateAdded, book[i].qtyOnHand, book[i].wholesale, book[i].retail, false);
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
        cout << "Title: " << book[i].bookTitle << endl;
        cout << "ISBN: " << book[i].isbn << endl;
        cout << "Quantity On hand: " << book[i].qtyOnHand << endl;
        cout << "Wholesale Cost: " << book[i].wholesale << endl;
        total += book[i].wholesale * book[i].qtyOnHand;
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
        if (strcmp(book[i].bookTitle, "") != 0) {
            cout << "Title: " << book[i].bookTitle << endl;
            cout << "ISBN: " << book[i].isbn << endl;
            cout << "Quantity On hand: " << book[i].qtyOnHand << endl;
            cout << "Retail Price: " << book[i].retail << endl;
            total += book[i].retail * book[i].qtyOnHand;
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
    int *qtyPtr[SIZE];
    int idPtr[SIZE];

    for (int i = 0; i < SIZE; i ++) {
        qtyPtr[i] = &book[i].qtyOnHand;
        idPtr[i] = i;
    }
    
    //selection sorting the array
    int i, j, max_idx; 

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if (*qtyPtr[j] > *qtyPtr[max_idx]) 
            max_idx = j; 

        //swapping the values
        int *temp = qtyPtr[max_idx];
        qtyPtr[max_idx] = qtyPtr[i];
        qtyPtr[i] = temp;
        int temp2 = idPtr[max_idx];
        idPtr[max_idx] = idPtr[i];
        idPtr[i] = temp2;
    } 

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        if (strcmp(book[idPtr[i]].bookTitle, "") != 0) {
            cout << "Title: " << book[idPtr[i]].bookTitle << endl;
            cout << "ISBN: " << book[idPtr[i]].isbn << endl;
            cout << "Quantity On hand: " << book[idPtr[i]].qtyOnHand << endl;
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
    cout << "You selected sorted cost report.\n";
    double *costPtr[SIZE];
    int idPtr[SIZE];
    for (int i = 0; i < SIZE; i ++) {
        costPtr[i] = &book[i].wholesale;
    }

    //selection sorting the array
    int i, j, max_idx;
    
    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if (*costPtr[j] > *costPtr[max_idx]) 
            max_idx = j; 

        //swapping the values
        double *temp = costPtr[max_idx];
        costPtr[max_idx] = costPtr[i];
        costPtr[i] = temp;
    }

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        if (strcmp(book[idPtr[i]].bookTitle, "") != 0) {
            cout << "Title: " << book[idPtr[i]].bookTitle << endl;
            cout << "ISBN: " << book[idPtr[i]].isbn << endl;
            cout << "Wholesale Cost: " << book[idPtr[i]].wholesale << endl;
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
    char *agePtr[SIZE];
    int idPtr[SIZE];
    for (int i = 0; i < SIZE-1; i ++) {   //make an array of pointers to the dateAdded array
        agePtr[i] = book[i].dateAdded;
        idPtr[i] = i;
    }

    //selection sorting the array
    int i, j, max_idx;

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE-1; j++) {

            if (strcmp(agePtr[j], agePtr[max_idx]) >= 0){
                max_idx = j; 
            }
        }

        //swapping the values of max and i
        char *temp = agePtr[max_idx];
        agePtr[max_idx] = agePtr[i];
        agePtr[i] = temp;
        int tem = idPtr[max_idx];
        idPtr[max_idx] = idPtr[i];
        idPtr[i] = tem;  
    }

    //printing the sorted array
    for (int i = 0; i < SIZE-1; i ++) {
        if (strcmp(agePtr[idPtr[i]], "") != 0) {
            cout << "Title: " << book[idPtr[i]].bookTitle << endl;
            cout << "ISBN: " << book[idPtr[i]].isbn << endl;
            cout << "Date Added: " << book[idPtr[i]].dateAdded << endl;
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