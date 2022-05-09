#ifndef INV_H
#define INV_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>
#include "bookdata.h"
#include "inventorybook.h"

using namespace std;

//making the array global so it can be accessed by other functions
extern InvBook book[];

//the data file
extern fstream invFile;

//prototypes
void invMenu();
void lookUpBook();
void addBook();
void editBook();
void deleteBook();

#endif