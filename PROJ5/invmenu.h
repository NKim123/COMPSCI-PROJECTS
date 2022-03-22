#ifndef INV_H
#define INV_H

#include <iostream>
#include <iomanip>

using namespace std;

//creating global arrays for the book info
extern string bookTitle[];
extern string isbn[];
extern string author[];
extern string publisher[];
extern string dateAdded[];
extern int qtyOnHand[];
extern double wholesale[];
extern double retail[];

//prototypes
void invMenu();
void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif