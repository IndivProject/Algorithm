#include <stdio.h>

int inputStack(int num,int list[], int length){
    list[length++] = num;
    return length;
}

int outputStack(int list[], int length){
    list[--length] = 0;
    return length;
}

int main(){
    int n, list[1000001], length = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int a,num=0;
        scanf("%d", &a);
        switch (a){
            case 1:
                scanf("%d", &num);
                length = inputStack(num, list, length);
                break;
            case 2:
                if(length == 0) printf("-1\n");
                else {
                    printf("%d\n", list[length-1]);
                    length = outputStack(list, length);
                }
                break;
            case 3:
                printf("%d\n",length);
                break;
            case 4:
                if(length == 0) printf("1\n");
                else printf("0\n");
                break;
            case 5:
                if(length == 0) printf("-1\n");
                else printf("%d\n", list[length-1]);
                break;
        }
    }
    
    return 0;
}