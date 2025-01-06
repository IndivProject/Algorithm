#include <stdio.h>
#include <math.h>

int check(int num){
    for(int i = 3;i<=sqrt(num);i+=2){
        if(num%i==0) return 0;
    }
    // printf("%d ",num);
    return 1;
}


int main(){
    int n, a=0;
    while (1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for (int i = n+1; i <= n*2; i++){
            if((i==2 || i%2!=0) && check(i)) a++;
        }
        printf("%d\n",a);
        a=0;
    }
    
    return 0;
}