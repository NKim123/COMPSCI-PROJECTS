#include "reports.h"
#include "invmenu.h"
#include "bookinfo.h"

const int SIZE = 20;
void report(){
    //clearing input buffer
    while(getchar() != '\n');
    
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

        //getting the user's choice with input validation
        do {
            cin >> choice;
            if (choice < 1 || choice > 7) {
                cout << "Invalid choice. (Please enter a number 1 - 7)\n";
                cout << "Enter your choice: ";
            }
        } while (choice < 1 || choice > 7);

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
                return;
                break;
        }
    }
}

//stub functions
void repListing() {
    cout << "You selected a listing report.\n";
    
    for (int i = 0; i < SIZE; i ++) {
        bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i], false);
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
    double total = 0;
    for (int i = 0; i < SIZE; i ++) {
        cout << "Title: " << bookTitle[i] << endl;
        cout << "ISBN: " << isbn[i] << endl;
        cout << "Quantity On hand: " << qtyOnHand[i] << endl;
        cout << "Wholesale Cost: " << wholesale[i] << endl;
        total += wholesale[i] * qtyOnHand[i];
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
        if (bookTitle[i] != "") {
            cout << "Title: " << bookTitle[i] << endl;
            cout << "ISBN: " << isbn[i] << endl;
            cout << "Quantity On hand: " << qtyOnHand[i] << endl;
            cout << "Retail Price: " << retail[i] << endl;
            total += retail[i] * qtyOnHand[i];
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
        qtyPtr[i] = &qtyOnHand[i];
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
    } 

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        idPtr[i] = qtyPtr[i] - qtyOnHand;
        if (bookTitle[idPtr[i]] != "") {
            cout << "Title: " << bookTitle[idPtr[i]] << endl;
            cout << "ISBN: " << isbn[idPtr[i]] << endl;
            cout << "Quantity On hand: " << qtyOnHand[idPtr[i]] << endl;
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
        costPtr[i] = &wholesale[i];
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
        idPtr[i] = costPtr[i]-&wholesale[0];
        if (bookTitle[idPtr[i]] != "") {
            cout << "Title: " << bookTitle[idPtr[i]] << endl;
            cout << "ISBN: " << isbn[idPtr[i]] << endl;
            cout << "Wholesale Cost: " << wholesale[idPtr[i]] << endl;
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
    string *agePtr[SIZE];
    int idPtr[SIZE];
    for (int i = 0; i < SIZE; i ++) {
        agePtr[i] = &dateAdded[i];
    }

    //selection sorting the array
    int i, j, max_idx;

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if (*agePtr[j] < *agePtr[max_idx]) 
            max_idx = j; 

        //swapping the values
        string *temp = agePtr[max_idx];
        agePtr[max_idx] = agePtr[i];
        agePtr[i] = temp;
    }

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        idPtr[i] = agePtr[i]-dateAdded;
        if (bookTitle[idPtr[i]] != "") { 
            cout << "Title: " << bookTitle[idPtr[i]] << endl;
            cout << "ISBN: " << isbn[idPtr[i]] << endl;
            cout << "Date Added: " << dateAdded[idPtr[i]] << endl;
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