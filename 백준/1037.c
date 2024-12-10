#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int n[t], bigValue = 0, minValue= 1000005;
    for(int i =0;i<t;i++) {
        scanf("%d", &n[i]);
        if(bigValue < n[i]) bigValue = n[i];
        if(minValue > n[i]) minValue = n[i];
    }

    printf("%d", bigValue*minValue);
    return 0;
}