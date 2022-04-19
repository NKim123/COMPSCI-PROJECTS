#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class BookData {
    private:
        char bookTitle[51];
        char isbn[14];
        char author[31];
        char publisher[31];
        char dateAdded[11];
        int qtyOnHand;
        double wholesale;
        double retail;

    public:
        BookData();
        void setTitle(string title);
        void setIsbn(string isbn);
        void setAuthor(string author);
        void setPublisher(string publisher);
        void setDateAdded(string dateAdded);
        void setQtyOnHand(int qtyOnHand);
        void setWholesale(double wholesale);
        void setRetail(double retail);
        char* getTitle();
        char* getIsbn();
        char* getAuthor();
        char* getPublisher();
        char* getDateAdded();
        int getQtyOnHand();
        double getWholesale();
        double getRetail();

        int isEmpty();
        void removeBook();
};


#endif