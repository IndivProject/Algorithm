#include <stdio.h>

int getLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

int main(){
    char a[103] = "level";

    fgets(a,sizeof(a), stdin);

    int length = getLength(a);
    int cplength = length-2;

    int flag = 1;

    for (int i = 0; i < length/2; i++,cplength--)
    {
        if(a[i] != a[cplength]) {
            flag = 0;
            break;
        }
    }

    printf("%d",flag);
    
    return 0;
}