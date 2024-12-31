#include <stdio.h>

long long int calculate(long long int n){
    if(n == 0) return 1;
    return calculate(n-1)*3;
}

void cantor(long long int n, int position){
    for (int i = 0; i < n; i++){
        if(position == 1) printf(" ");
        else {
            if(i == 1) printf(" ");
            else printf("-");
        }
    }
}

void print(long long int n, int position){
    if(n>1){
        // printf("%d %d / ",n, position);
        print(n/3, position!=1 ? 0: 1);
        print(n/3, 1);
        print(n/3, position!=1 ? 0: 1);
        if(n==3) cantor(n, position);
    }
}

int main(){
    long long int n;
    while(scanf("%lld",&n) != -1){
        
        n = calculate(n);

        // printf("%d",n);
        if(n == 1) printf("-");
        print(n, 0);
        printf("\n");
    }

    return 0;
}