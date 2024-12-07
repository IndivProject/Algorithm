#include <stdio.h>

int check(int number){
    
    for(int i = 2; i<=number/2;i++){
        if(number % i == 0) return 0;
    }
    return 1;
}

int main(){
    int number = 0, count = 0;
    int n = 0;
    scanf("%d", &n);
    for(int i =0;i<n;i++){
        scanf("%d", &number);
        if(number > 1 && check(number)) count++;
    }
    printf("%d", count);
    return 0;
}