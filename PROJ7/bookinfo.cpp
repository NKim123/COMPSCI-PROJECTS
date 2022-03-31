#include "bookinfo.h"

void bookInfo(char isbn[14], char title[51], char author[31], char publisher[31], char dateAdded[11], int qtyOnHand, double wholesale, double retail, bool showInfo) {

    //printing book info
    if (showInfo) {cout << setw(30) << right << "Serendipity Booksellers\n" << setw(28) << "Book Information\n\n";}
    cout << "ISBN:" << setw(30) << right << isbn << endl; 
    cout << "Title:" << setw(29) << right << title << endl;
    cout << "Author:" << setw(28) << right << author << endl;
    cout << "Publisher:" << setw(25) << right << publisher << endl;
    cout << "Date Added:" << setw(24) << right << dateAdded << endl;
    cout << "Quantity:" << setw(26) << right << qtyOnHand << endl;
    cout << "Wholesale Cost:" << setw(20) << right << wholesale << endl;
    cout << "Retail Price:" << setw(22) << right << retail << endl << endl;
}