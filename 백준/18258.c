#include <stdio.h>
#include <string.h>

int main(){
    int n, queue[2000000] ={0}, front = 0, back = 0;
    scanf("%d", &n);
    char method[7];
    for (int i = 0, a = 0; i < n; i++){
        scanf("%s",method);
        if(strcmp(method, "push") == 0){
            // printf("pushppp==\n");
            scanf("%d",&a);
            queue[front++] = a;
            // printf("%d\n",queue[front-1]);
        }else if(strcmp(method, "pop") == 0){
            printf("%d\n",queue[back] == 0 ? -1 : queue[back++]);
        }else if(strcmp(method, "size") == 0){
            printf("%d\n", front-back);
        }else if(strcmp(method, "empty") == 0) printf("%d\n", front-back == 0 ? 1 : 0);
        else if(strcmp(method, "back") == 0){
            printf("%d\n", front-back == 0 ? -1 : queue[front-1]);
        }else if(strcmp(method, "front") == 0){
            printf("%d\n", front-back == 0 ? -1 : queue[back]);
        }
    }
    
    return 0;
}