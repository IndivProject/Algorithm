#include <stdio.h>

int main(){
    char num[11];
    fgets(num, sizeof(num),stdin);

    for (int i = 0; num[i] != '\0'; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (num[i] > num[j])
            {
                num[i] ^= num[j];
                num[j] ^= num[i];
                num[i] ^= num[j];
            }
            
        }
        
    }
    

    printf("%s",num);
    return 0;
}