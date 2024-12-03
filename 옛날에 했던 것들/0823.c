#include <stdio.h>
#define LEN 20;
struct names{
    char first[LEN];
    char last[LEN];
};

struct guy{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    int income;
};

int main(){
    static struct guy fellow[2]={
        {{"Min woo", "Kwon"},"bolgogi", "talent",5000},
        {{"Hyun Ah"},"Jo"},
        "pizza",
        "teacher",
        3500
    };
    struct guy *him;
    printf("#1 : %u\t #2 : %u\n",&fellow[0], &fellow[0]);
    him = &fellow[0];
    printf("(1) %u\t")
}