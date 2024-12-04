#include <stdio.h>

int getLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

int main() {
    char myString[101];
    scanf("%s", myString);
    printf("%d", getLength(myString));
    return 0;
}