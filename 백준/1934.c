#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    for (int i = 0,a,b; i < t; i++){
        scanf("%d %d", &a, &b);
        if (a<b){
            if(b%a == 0) printf("%d\n",b);
            else{
                for (int i = 1,flag = 1; i <= a && flag; i++){
                    if(b*i%a== 0) {
                        printf("%d\n",b*i);
                        flag = 0;
                    }
                }
            }
        }else if(a > b){
            if(a%b == 0) printf("%d\n",a);
            else{
                for (int i = 1,flag = 1; i <= b && flag; i++){
                    if(a*i%b== 0) {
                        printf("%d\n",a*i);
                        flag = 0;
                    }
                }
            }
        }
        else
            printf("%d\n",b);
                
    }
    
    return 0;
}