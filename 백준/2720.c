#include <stdio.h>

int main(){
    int testCount = 0;
    scanf("%d", &testCount);
    int testCase[testCount];

    for (int i = 0; i < testCount; i++) scanf("%d", &testCase[i]);

    for(int i = 0; i < testCount; i++)
        printf("%d %d %d %d\n", testCase[i]/25,(testCase[i]%25)/10,(testCase[i]%25%10)/5,(testCase[i]%25%10%5));
    return 0;
}