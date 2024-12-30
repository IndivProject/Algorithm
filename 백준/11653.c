#include <stdio.h>

int divide(int n){
    for (int i = 2; i <= n/2; i++){
        if(n%i == 0) {
            printf("%d\n",i);
            n/=i;
            return divide(n);
        }
        
    }
    return n;
}

int main(){
    int n;
    scanf("%d",&n);
    if(n != 1) printf("%d",divide(n));
    return 0;
}