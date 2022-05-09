#include "inVal.h"

inVal::inVal(){
    input = "";
    intInput = 0;
}

void inVal::getInputString() {
    cin >> this->input;
}

void inVal::getInputInt() {
    cin >> this->intInput;
}

void inVal::clear() {
    this->input = "";
    this->intInput = 0;
}

bool inVal::inValString(string option1, string option2) {
    do {
        this->getInputString();
        if (input == option1 || input == option2) {
            return true;
        } else {
            cout << "Invalid input. Please enter " << option1 << " or " << option2 << ": ";
        }
    }  while (true);
    
}

bool inVal::inValInt(int input1, int input2) {
    do {
        this->getInputInt();
        if (this->intInput >= input1 && this->intInput <= input2) {
            return true;
        } else {
            cout << "Invalid input. Please enter a number between " << input1 << " and " << input2 << ": ";
        }
    } while(true);
}

int inVal::showInputInt() {
    return this->intInput;
};

string inVal::showInputString() {
    return this->input;
};
