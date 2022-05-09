#include "inventorybook.h"

InvBook::InvBook(){
    dateAdded[0] = '\0';
    qtyOnHand = 0;
    wholesale = 0.0;
    retail = 0.0;
}


void InvBook::setDateAdded(string dateAdded){
    strcpy(this->dateAdded, dateAdded.c_str());
}

void InvBook::setQtyOnHand(int qtyOnHand){
    this->qtyOnHand = qtyOnHand;
}

void InvBook::setWholesale(double wholesale){
    this->wholesale = wholesale;
}

void InvBook::setRetail(double retail){
    this->retail = retail;
}

char* InvBook::getAuthor(){
    return author;
}

char* InvBook::getPublisher(){
    return publisher;
}

char* InvBook::getDateAdded(){
    return dateAdded;
}

char* InvBook::getTitle(){
    return bookTitle;
}

char* InvBook::getIsbn(){
    return isbn;
}

int InvBook::getQtyOnHand(){
    return qtyOnHand;
}

double InvBook::getWholesale(){
    return wholesale;
}

double InvBook::getRetail(){
    return retail;
}

int InvBook::isEmpty(){
    if (bookTitle[0] == '\0' && isbn[0] == '\0' && author[0] == '\0' && publisher[0] == '\0' && dateAdded[0] == '\0' && qtyOnHand == 0 && wholesale == 0.0 && retail == 0.0) {
        return 1;
    }
    else {
        return 0;
    }
}

void InvBook::removeBook(){
    bookTitle[0] = '\0';
    isbn[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
    dateAdded[0] = '\0';
    qtyOnHand = 0;
    wholesale = 0.0;
    retail = 0.0;
}

bool InvBook::bookMatch(char* title){
    if (strstr(this->bookTitle, title)) {
        return true;
    }
    else {
        return false;
    }
}

