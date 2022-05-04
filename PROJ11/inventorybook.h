#ifndef INVENTORYBOOK_H
#define INVENTORYBOOK_H

#include <iostream>
#include <string>
#include <cctype>
#include "bookdata.h"

using namespace std;

class InvBook : public BookData {
    private:
        char dateAdded[11];
        int qtyOnHand;
        double wholesale;
        double retail;
        friend class SoldBook;

    public:
        InvBook();
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
        bool bookMatch(char* title);
};


#endif