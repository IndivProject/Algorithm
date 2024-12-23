#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int num[n], length = 0, total = 0;

    for (int i = 0,a; i < n; i++){
        scanf("%d",&a);
        if(a == 0){
            length - 1 < 0 ? length = 0 : length--;
            total -= num[length];
            num[length] = 0;
        }
        else{
            num[length] = a;
            total += num[length++];
        }
    }
    
    printf("%d", total);
    
    return 0;
}