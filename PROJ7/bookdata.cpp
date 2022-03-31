struct BookData {
    #include "bookdata.h"

    char bookTitle[51];
    char isbn[14];
    char author[31];
    char publisher[31];
    char dateAdded[11];
    int qtyOnHand;
    double wholesale;
    double retail;

    void setTitle(str *title, int i) {
        strcpy(bookTitle[i], title);
    }

    void setIsbn(str *isbn, int i) {
        strcpy(isbn[i], isbn);
    }

    void setAuthor(str *author, int i) {
        strcpy(author[i], author);
    }

    void setPub(str *pub, int i) {
        strcpy(publisher[i], pub);
    }

    void setDateAdded(str *date, int i) {
        strcpy(dateAdded[i], date);
    }

    void setQty(int qty, int i) {
        qtyOnHand[i] = qty;
    }

    void setWholesale(double w, int i) {
        wholesale[i] = w;
    }

    void setRetail(double r, int i) {
        retail[i] = r;
    }
};