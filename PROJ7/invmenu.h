#ifndef INV_H
#define INV_H

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

extern char bookTitle[][51];
extern char isbn[][14];
extern char author[][31];
extern char publisher[][31];
extern char dateAdded[][11];
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