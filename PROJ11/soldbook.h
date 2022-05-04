#ifndef SOLDBOOK_H
#define SOLDBOOK_H

#include <iostream>
#include <string>
#include <cctype>
#include "inventorybook.h"

class SoldBook : public InvBook {
    private:
        const static double TAX_RATE = 0.06;
        int qtySold;
        double tax, subtotal;
        const static double total;

    public:
        SoldBook();
        void setDateSold(string dateSold);
        void setQtySold(int qtySold);
        void setTotal(double total);
        char* getTitle();
        char* getIsbn();
        char* getAuthor();
        char* getPublisher();
        char* getDateAdded();
        int getQtyOnHand();
        double getWholesale();
        double getRetail();
        char* getDateSold();
        int getQtySold();
        double getTotal();

        int isEmpty();
        void removeBook();
        bool bookMatch(char* title);
};

#endif
