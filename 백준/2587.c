#include <stdio.h>

int main(){
    int a[5], sum =0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
        for (int j = 0; j <= i; j++)
        {
            if (a[i] < a[j]){
                a[i]^= a[j];
                a[j]^= a[i];
                a[i]^= a[j];
            }
        }
    }

    printf("%d\n%d",sum/5, a[2]);
    
    return 0;
}