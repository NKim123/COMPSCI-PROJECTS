#ifndef INV_H
#define INV_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include "bookdata.h"

using namespace std;

extern BookData book[];

//prototypes
void invMenu();
void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif