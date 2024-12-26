#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int queue[n*2+1], front =n, back = n;
    for (int i = 0, a = 0, val = 0; i < n; i++){
        scanf("%d",&a);

        switch (a){
        case 1:
            scanf("%d", &val);
            queue[back++] = val;
            break;
        case 2:
            scanf("%d", &val);
            queue[--front] = val;
            break;
        case 3:
            if(back - front == 0) printf("-1\n");
            else printf("%d\n",queue[back-=1]);
            break;
        case 4:
            if(back - front == 0) printf("-1\n");
            else 
                printf("%d\n",queue[front++]);
            break;
        case 5:
            printf("%d\n", back - front);
            break;
        case 6:
            printf("%d\n", back - front == 0 ? 1 : 0);
            break;
        case 7:
            printf("%d\n", back - front == 0 ? -1 : queue[back-1]);
            break;
        case 8:
            printf("%d\n", back - front == 0 ? -1 : queue[front]);
            break;
        }

    }
    

    return 0;
}