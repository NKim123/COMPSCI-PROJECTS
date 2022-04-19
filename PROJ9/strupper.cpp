#include "strupper.h"
//makes cstring uppercase
char* strUpper(char* str){
    while (*str != 0){
        *str = toupper(*str);
        str++;
    }
    return str;
}