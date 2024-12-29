#include <stdio.h>

int main(){
    int n;
    while (1){
        int a=0;
        scanf("%d",&n);
        if(n == -1) break;
        for (int i = 1; i <= n/2; i++){
            if(n%i == 0) a+=i;
        }
        if(a == n){
            printf("%d = 1", n);
            for (int i = 2; i <= n/2; i++) if(n%i == 0) printf(" + %d",i);
            printf("\n");
        }else printf("%d is NOT perfect.\n",n);
        
    }
    
    return 0;
}