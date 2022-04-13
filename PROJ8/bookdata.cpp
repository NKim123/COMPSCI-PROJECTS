#include "bookdata.h"

BookData::BookData(){
    bookTitle[0] = '\0';
    isbn[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
    dateAdded[0] = '\0';
    qtyOnHand = 0;
    wholesale = 0.0;
    retail = 0.0;
}

void BookData::setTitle(string title){
    strcpy(bookTitle, title.c_str());
}

void BookData::setIsbn(string isbn){
    strcpy(this->isbn, isbn.c_str());
}

void BookData::setAuthor(string author){
    strcpy(this->author, author.c_str());
}

void BookData::setPublisher(string publisher){
    strcpy(this->publisher, publisher.c_str());
}

void BookData::setDateAdded(string dateAdded){
    strcpy(this->dateAdded, dateAdded.c_str());
}

void BookData::setQtyOnHand(int qtyOnHand){
    this->qtyOnHand = qtyOnHand;
}

void BookData::setWholesale(double wholesale){
    this->wholesale = wholesale;
}

void BookData::setRetail(double retail){
    this->retail = retail;
}

int BookData::isEmpty(){
    if (bookTitle[0] == '\0' && isbn[0] == '\0' && author[0] == '\0' && publisher[0] == '\0' && dateAdded[0] == '\0' && qtyOnHand == 0 && wholesale == 0.0 && retail == 0.0) {
        return 1;
    }
    else {
        return 0;
    }
}

void BookData::removeBook(){
    bookTitle[0] = '\0';
    isbn[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
    dateAdded[0] = '\0';
    qtyOnHand = 0;
    wholesale = 0.0;
    retail = 0.0;
}

