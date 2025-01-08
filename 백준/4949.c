#include <stdio.h>
#include <string.h>

int main(){
    char str[110];
    while (1)
    {
        fgets(str,sizeof(char)*110,stdin);

        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }

        int i = 0, flag = 1;
        int check = 0, open = 0, bigOpen = 0;
        char maybe[101], idx = 0;

        for (;flag && str[i] !='\0'; i++){
            if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']'){
                switch (str[i]){
                case '('://1
                    check = 1;
                    open++;
                    maybe[idx++] = ')';
                    break;
                case ')'://2
                    if(maybe[--idx] != ')') flag = 0;
                    if(check == 0 || check == 3) flag = 0;
                    check = 2;
                    open--;
                    break;
                case '['://3
                    check = 3;
                    open++;
                    maybe[idx++] = ']';
                    break;
                case ']'://4
                    if(maybe[--idx] != ']') flag = 0;
                    if(check == 0 || check == 1) flag = 0;
                    check = 4;
                    open--;
                    break;
                }
            }
        }

        if(i-1 <= 1 && str[0]== '.') break;
        
        if(flag) {
            if(open != 0 || (check == 1 || check == 3)) printf("no\n");
            else printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}