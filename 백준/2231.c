#include <stdio.h>

int check(int num){
    for (int i = num/2; i < num; i++){
        int n = i, a = 0;
        // printf("%d ",n);
        for (int j = 1; j<n; j*=10){
            // printf("%d ",(n%(j*10))/j);
            a += (n%(j*10))/j;
        }
        n+=a;
        // printf("\n-%d-\n",n);
        if(n == num) return i;
    }
    
    return 0;
}

int main(){
    int num=0;
    scanf("%d",&num);
    printf("%d",check(num));

}