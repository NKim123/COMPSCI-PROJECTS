#ifndef INVAL_H
#define INVAL_H
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class inVal {
    private:
        string input;
        int intInput;
    public:
        inVal();
        void getInputString(); //gets input as a string
        void getInputInt(); //gets int input
        void clear(); //clears input
        bool inValString(string, string); //checks if input is one of two options
        bool inValInt(int, int); //checks if input is within range
        int showInputInt(); //returns int input
        string showInputString(); //returns string input
};

#endif