#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d",&a,&b);
    scanf("%d %d",&c,&d);
    
    c *= b;
    a = (a * d) + c;
    b *= d;
    // printf("%d %d %d %d\n", a, a/2+1, b, b/2+1);

    int x[30000]={0}, y[30000]={0};

    int count = a > b ? a : b;

    for (int i = 2,x1=0,y1=0; i <= count/2; i++){
        if(a != i && a%i==0)
            x[x1++]=i;
        if(b != i && b%i==0) {
            y[y1++]=i;
            // printf("%d ",i);
        }
    }
    // printf("\n");

    int divide = 1;

    if(a == b) divide = a;
    else if(a % b == 0){
        divide = b;
    }else if(b % a == 0){
        divide = a;
    }
    else{
        for (int x1 =0, y1=0;;){
            if(x[x1] == 0 || y[y1] == 0) break;
            if(x[x1] > y[y1])
                y1++;
            else if(x[x1] < y[y1])
                x1++;
            else {
                divide = x[x1];
                x1++;
                y1++;
            }
        }
    }

    printf("%d %d", a/divide, b/divide);
    

    return 0;
}