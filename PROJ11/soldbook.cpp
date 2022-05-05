#include "soldbook.h"

double SoldBook::total = 0.0;
double SoldBook::TAX_RATE = 0.6;

SoldBook::SoldBook(){
    int qtySold = 0;
    double tax = 0.0, subtotal = 0.0, total = 0.0;
}

void SoldBook::setQtySold(int qtySold){
    this->qtySold = qtySold;
}

double SoldBook::setTax(){
    this->tax = qtySold * this->retail * TAX_RATE;
    return tax;
}

double SoldBook::setSubtotal(){
    this->subtotal = qtySold * this->retail + this->tax;
    return subtotal;
}

double SoldBook::getTax() {
    return this->tax;
}

void SoldBook::addTotal(double total) {
    this->total += total;
}

double SoldBook::getTotal() {
    return this->total;
}