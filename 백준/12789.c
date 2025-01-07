#include <stdio.h>

int check(int stack[], int stack1[], int idx, int idx1, int n, int num){
    // printf("%d %d %d %d %d\n",stack[idx], idx, stack1[idx1], idx1, num);
    if(num == n) return 1;

    if(idx >= n){
        // printf("ih\n");
        if(idx1 == 0) return 1;
        for (int i = idx1; i >= 0; i--){
            // printf("%d %d %d\n", stack1[i], i ,num);
            if(stack1[i] != num) return 0;
            num++;
        }
        return 1;
    }else{
        if(stack[idx] == num){
            // printf("why %d %d\n",num, stack[idx]);
            return check(stack, stack1, idx+1, idx1, n, num+1);
        }else{
            if(stack1[idx1] == num){
                return check(stack, stack1, idx, idx1-1, n, num+1);
            }
            else{
                // printf("wtf %d %d\n",stack1[idx1], stack[idx]);
                stack1[++idx1] = stack[idx];
                // printf("wtf %d %d\n",stack1[idx1], stack[idx]);
                // for (int i = 0; i < idx1; i++) printf("- %d ", stack1[i]);                
                return check(stack, stack1, idx+1, idx1, n, num);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int stack[n], stack1[n], idx = 0, idx1=0, num = 1;
    for (int i= 0; i < n; i++){
        scanf("%d",&stack[i]);
        if(stack[i] == 1){
            idx = i;
            idx1 = i-1;
        }
        if(idx == 0) stack1[i] = stack[i];
    }

    // printf("1st : %d %d\n",idx, idx1);

    int flag = check(stack, stack1, idx, idx1, n, num);
    // int flag = 1;

    printf("%s", flag ? "Nice": "Sad");

    return 0;
}