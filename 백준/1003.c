#include <stdio.h>

int check0Arr[100] = {0};
int check1Arr[100] = {0};

void fibonacci(int n) {
    if (n == 0) {
        check0Arr[0] = 1;
    } else if (n == 1) {
        check1Arr[1] = 1;
    } else {
        check0Arr[n] += check0Arr[n-1] + check0Arr[n-2];
        check1Arr[n] += check1Arr[n-1] + check1Arr[n-2];
    }
}

int main(){
    int t = 0;
    scanf("%d", &t);
    int value[t];
    for(int i = 0; i<100; i++)
        fibonacci(i);
    for(int i =0;i<t;i++)
        scanf("%d", &value[i]);
    for(int i =0;i<t;i++)
        printf("%d %d\n", check0Arr[value[i]], check1Arr[value[i]]);
    return 0;
}