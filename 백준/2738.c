#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    int num[n][m];
    for(int i = 0; i<n*2; i++){
        for(int j =0;j<m;j++){
            if(i>=n){
                int a =0;
                scanf("%d",&a);
                // printf("%d %d %d \n",num[i-n][m],i-n,m);
                // printf("%d ",num[i-n][j]);
                num[i-n][j]+=a;
            }else{
                scanf("%d",&num[i][j]);
            }
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++)printf("%d ",num[i][j]);
        printf("\n");
    }

    return 0;
}