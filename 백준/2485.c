#include <stdio.h>

int main(){
    int n, min = 1000000001, temp = 0;
    scanf("%d",&n);
    int num[n], space[n-1], divide = 1;
    for (int i = 0; i < n; i++){
        scanf("%d",&num[i]);
        if(i!=0){
            space[i-1] = num[i]-num[i-1];
            if(min > space[i-1]) min = space[i-1];
        }
    }

    for (int i = 1, flag = 0,even=0; i <= min; i++){
        flag = 0;
        for (int j = 0; j < n-1; j++){
            if(!flag && space[j]%i != 0) {
                flag = 1; 
                break;
            }
        }
        if(!flag) divide = i;
    }
    
    for (int i = 0; i < n-1; i++){
        temp += space[i]/divide-1;
    }
    
    printf("%d",temp);
    
    return 0;
}