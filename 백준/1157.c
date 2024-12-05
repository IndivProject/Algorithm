#include <stdio.h>

int main(){
    char a[1000003];
    int check[26] = {0};

    char Alphabet = 'A';
    int manyUse = 0;
    fgets(a,sizeof(a), stdin);

    for (int i = 0; a[i] != '\0'; i++)
    {
        if(a[i] > 94) a[i] -= 32;
        check[a[i]-65]++;
    }
    
    for(int i = 0; i< 26;i++){
        if(manyUse < check[i]) {
            Alphabet = i + 65;
            manyUse = check[i];
        }
        else if(manyUse == check[i]) Alphabet = '?';
        
    }

    printf("%c", Alphabet);
    return 0;
}