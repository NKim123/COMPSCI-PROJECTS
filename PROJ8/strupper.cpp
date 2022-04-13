#include <cctype>
//makes cstring uppercase
void strUpper(char* str){
    while (*str != 0){
        *str = toupper(*str);
        str++;
    }
}