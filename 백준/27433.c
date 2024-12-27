#include <stdio.h>

long long int fac(long long int i){
    if(i == 1) return 1;
    return i * fac(i-1);
}

int main(){
    int n = 1;
    scanf("%d", &n);
    if(n == 0) n =1;
    printf("%lld", fac(n));
    return 0;
}