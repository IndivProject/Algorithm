#include <stdio.h>

int main(){
    int triangle[3] = {0,0,0};
    int check = 0;
    
    while(1){
        scanf("%d %d %d", &triangle[0],&triangle[1],&triangle[2]);
        float a = triangle[0] + triangle[1];
        if(a+triangle[2] == 0) break;
        int check = 0;

        if(triangle[0] > triangle[1] && triangle[0] > triangle[2]) {
            if(triangle[0] >= triangle[1] + triangle[2]) check = 1;
        }else if(triangle[1] > triangle[2] && triangle[1] > triangle[0]){
            if(triangle[1] >= triangle[0] + triangle[2]) check = 1; 
        }else if(triangle[2] > triangle[1] && triangle[2] > triangle[0]) {
            if(triangle[2] >= triangle[1] + triangle[0]) check = 1;
        }
        if(check){
            check = 0;
            printf("Invalid\n");
        }else{
            if(a / 2 == (float)triangle[2]) printf("Equilateral\n");
            else {
                if(a / 2 == (float)triangle[0] || a - triangle[2] == triangle[1] || a - triangle[2] == triangle[0]) printf("Isosceles\n");
                else  printf("Scalene\n");
            }
        }
    }
    return 0;
}