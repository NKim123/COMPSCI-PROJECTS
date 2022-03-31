#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct BookData {
    char bookTitle[51];
    char isbn[14];
    char author[31];
    char publisher[31];
    char dateAdded[11];
    int qtyOnHand;
    double wholesale;
    double retail;

    void setTitle(*str, int);
    void setIsbn(*str, int);
    void setAuthor(*str, int);
    void setPub(*str, int);
    void setDateAdded(*str, int);
    void setQty(int, int);
    void setWholesale(double, int);
    void setRetail(double, int);

    int isEmpty(int);
    int removeBook(int);
};


#endif