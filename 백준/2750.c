#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        for (int j = 0; j <= i; j++)
        {
            if (a[i] < a[j]){
                a[i]^= a[j];
                a[j]^= a[i];
                a[i]^= a[j];
            }
        }
    }

    for (int i = 0; i < n; i++) printf("%d\n", a[i]);
    
    return 0;
}