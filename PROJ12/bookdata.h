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
        friend class InvBook;

    public:
        BookData();
        void setTitle(string title);
        void setIsbn(string isbn);
        void setAuthor(string author);
        void setPublisher(string publisher);
};


#endif