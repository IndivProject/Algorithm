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
    long long int n,m;
    scanf("%lld %lld", &n, &m);
    for (int i = n; i <= m; i++){
        if(i >= 2){
            if(i==2) printf("2\n");
            else
                if(i%2!=0)
                    if(check(i))
                        printf("%d\n",i);
        }
    }
    return 0;
}