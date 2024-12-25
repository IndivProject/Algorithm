#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int queue[n * 2], front = 0, back = 0;
    for(int i = 0; i< n;i++, back++){
        queue[i] = i+1;
        // printf("%d,\n", queue[i]);
    }

    // printf("b : %d\n",back);

    for(;back-front != 1;){
        // printf("%d %d %d \n", front, back, queue[front]);
        front++;
        queue[back++] = queue[front++];
        // printf("%d %d %d \n", front, back, queue[front]);
        // printf("mm\n");
    }
    printf("%d",queue[front]);
    return 0;
}