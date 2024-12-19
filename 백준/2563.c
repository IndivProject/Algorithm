#include <stdio.h>

int main(){
    int papers, num= 0;
    int area[101][101] ={0};
    scanf("%d",&papers);
    for (int i = 0, x, y; i < papers; i++){
        scanf("%d %d",&x, &y);
        for (int j = 0; j < 10; j++)
        {
            for(int k = 0; k<10;k++){
                if(area[x+j][y+k] == 0){
                    num++;
                    area[x+j][y+k] = 1;
                }
            }
        }
    }

    printf("%d", num);
    
    return 0;
}