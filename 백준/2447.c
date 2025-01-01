#include <stdio.h>

// void star(int n, int count, int y, int position){
//     int a = n/3;
//     for (int i = 0; i < n; i++){
//         if(i%a >= n/a && i%a < (n/a)*2) printf("-");
//         else if(position == 1 && count >= n && count < n*2) printf(" ");
//         else{
//             if(count % 3 == 1 && i % 3 == 1) printf(" ");
//             else{
//                 if(y%3==2 && i >= n/3 && i < (n/3)*2) printf(" ");
//                 else printf("*");
//             }
//         }
//     }
// }

/*
            if(y%3==0){
                // if(power <= y && power*2 > y){
                //     if(i*3 >= power && i*3 < power*2) star(n, 2);
                //     else star(n, 0);
                // }
                // else star(n, 0);
            }
            else if(y%3 ==1){
                // if(power <= y && power*2 > y) {
                //     if(i*3 >= power && i*3 < power*2) star(n, 2);
                //     else star(n, 1);
                // }
                // else star(n, 1);
            }
            else if(y%3 == 2){
                // if(power <= y && power*2 > y){
                //     if(i*3 >= power && i*3 < power*2) star(n, 2);
                //     else star(n, 0);
                // }
                // else star(n, 0);
            }
*/

void star(int n, int position){
    int i = 0;
    for (; i < n; i++){
        if(position == 0) printf("*");
        else if(position == 1){
            if(i==1) printf(" ");
            else printf("*");
        }else if(position == 2) printf(" ");
    }
}



void print(int n, int y, int count, int power){
    if(y >= power*3) return;

    if(n > 3) print(n/3, y, count+1, power*=3);
    else{
        int flag = 0;
        for (int i = 0; i < power; i++){
            for (int a = 1; a < power;){
                a*=3;
                if((i%a >= a/3 && i%a < a-a/3) && (y%(a*3)>= a && y%(a*3) < a*2)){
                    // printf("%d",a);
                    flag = 1;
                    break;
                }
            }
            if(y%3==0){
                if(flag) star(n,2);
                else star(n, 0);
            }
            else if(y%3 ==1){
                if(flag) star(n,2);
                else star(n, 1);
            }
            else if(y%3 == 2){
                if(flag) star(n,2);
                else star(n, 0);
            }
            flag = 0;
            // printf("%d",i);
        }
        printf("\n");

        print(n,y+1,count, power);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    // int star[n][n]; 최후의 방법

    print(n, 0, 0, 1);
    
    return 0;
}