#include <stdio.h>

int getSpace(const char *str) {
    int length = 0, space = 0;
    while (str[length] != '\0'){
         length++;
         if(length != 0 && str[length] == ' ') space++;
    }
    if(str[length-2] == ' ') return --space;
    return space;
}

int main() {
    char myString[1000003] = {'\0'};
    fgets(myString,sizeof(myString), stdin);
    printf("%d", getSpace(myString)+1);
    return 0;
}