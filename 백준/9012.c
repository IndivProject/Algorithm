#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    char vps[50];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",vps);
        if(strlen(vps) %2 != 0) printf("NO\n");
        else{
            int a= 0, flag =1;
            for (int j = 0; j < strlen(vps); j++)
            {
                if(vps[j]== '(') a++;
                else a--;

                if(a < 0) flag = 0;
            }
            if(flag && a == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
    
    return 0;
}