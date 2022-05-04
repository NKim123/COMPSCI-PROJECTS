#include "bookdata.h"

BookData::BookData(){
    bookTitle[0] = '\0';
    isbn[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
}

void BookData::setTitle(string title){
    strcpy(this->bookTitle, title.c_str());
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

char* BookData::getAuthor(){
    return author;
}

char* BookData::getPublisher(){
    return publisher;
}

char* BookData::getDateAdded(){
    return dateAdded;
}

char* BookData::getTitle(){
    return bookTitle;
}

char* BookData::getIsbn(){
    return isbn;
}

int BookData::getQtyOnHand(){
    return qtyOnHand;
}

double BookData::getWholesale(){
    return wholesale;
}

double BookData::getRetail(){
    return retail;
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

bool BookData::bookMatch(char* title){
    if (strstr(this->bookTitle, title)) {
        return true;
    }
    else {
        return false;
    }
}

