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


