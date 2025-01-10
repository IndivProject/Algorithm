#include <stdio.h>
#include <string.h>

int a = 0;

int recursion(const char *s, int l, int r){
    a++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int n;
    scanf("%d",&n);
    char str[1001];
    for (int i = 0; i < n; i++){
        scanf("%s",str);
        int b = isPalindrome(str);
        printf("%d %d\n", b, a);
        a= 0;
    }
    
    return 0;
}