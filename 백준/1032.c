#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    char file[51];
    char pattern[51];
    scanf("%s",pattern);
    while(--n > 0){
        scanf("%s",file);
        int len = strlen(file) >= strlen(pattern) ? strlen(file) : strlen(pattern);
        for (int i = 0; i < len; i++)
            if(file[i] != pattern[i]) pattern[i] = '?';
    }
    
    printf("%s",pattern);
    return 0;
}