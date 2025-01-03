#include <stdio.h>
#include <math.h>

int check(long long int num){
    int i = 3;
    for (; i <= sqrt(num); i+=2)
        if(num%i == 0)
            return 0;
    return 1;
}

int main(){
    long long int n, num =0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld",&num);
        if(num <= 2) printf("2\n");
        else{
            for (int j = 0;; j++){
            if((num+j)%2!=0){
                if(check(num+j)){
                    printf("%lld\n",num+j);
                    break;
                }
            }
        }
        }
    }
    return 0;
}