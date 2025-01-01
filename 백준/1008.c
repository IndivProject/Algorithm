#include <stdio.h>

void calculate(int n, int m, int count){
    int num = (n*10)/m;
    if(n%m== 0) num = n/m;
    if((n*10)%m == 0 || count >= 11) printf("%d",num);
    else{
        printf("%d",num);
        calculate((n*10)%m, m, count + 1);
    }
}


int main(){
    double n, m;
    scanf("%lf %lf",&n, &m);
    printf("%.9lf",n/m);
    
    // int num = (n*10)/m;
    // // if(num)
    // if(n%m != 0) printf("0.");
    // calculate(n, m, 0);

    return 0;
}