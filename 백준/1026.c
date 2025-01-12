#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n], b[n], sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        for (int j = 0; j < i; j++){
            if(a[i] > a[j]){
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&b[i]);
        for (int j = 0; j < i; j++){
            if(b[i] < b[j]){
                b[i] ^= b[j];
                b[j] ^= b[i];
                b[i] ^= b[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];

    printf("%d", sum);
    return 0;
}