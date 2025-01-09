#include <stdio.h>

int main(){
    int n, a= 1, count = 1;
    scanf("%d", &n);
    for (int i = 1;; i++)
    {
        if(n <= a) break;
        count++;
        a += i*6;
    }

    printf("%d",count);
    
    return 0;
}