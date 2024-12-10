#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int a = 1;
    for(int i =1;i<=n;i++) a *= i;
    printf("%d", a);
    return 0;
}