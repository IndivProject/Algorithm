#include <stdio.h>
#define N 4

int foo(int matrix[][N],int row, int col, int dr, int dc, int le){
    int i, sum =0;
    for(int i=0;i<=le-1;i++){
        sum+=matrix[row][col];
        row+=dr;
        col+=dc;
    }
    return sum;
}

int main(){
    int m[N][N] = {1,3,5,7, 9,2,4,6, 8,1,3,5, 7,2,4,6},r,k;
    for(k=1;k<=N-1;k++){
        r=foo(m,0,k-1,1,-1,k)+foo(m,k,N-1,1,-1,N-k);
        printf("%d ",r);
    }
}

// int k[] = {-3,2,0,1},a,r[8]={0,};
// for(a=0;a<=3;a++) r[k[a]+4]++;
// r[0]=1;
// for(a=1;a<=7;a++)r[a]+=r[a-1];
// for(a=0;a<=3;a++)printf("%d %d\n",k[a],r[k[a]+3]);

// int naji(int a,int b,int m){
//     int r;
//     if(b==0)
//         return 1;
//     r = naji(a,b/2,m);
//     r = (r*r)%m;
//     if(b % 2 == 1 ) r = (r*a)%m;
//     return r;
// }

// int main(){
//     printf("%d\n",naji(2,3,9));
//     printf("%d\n",naji(3,15,10));
//     printf("%d 끝\n",naji(3,32130,10));
//     return 0;
// }