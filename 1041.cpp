#include <stdio.h>
#define MAXBETS 10005
#define MAXN 100005

int counts[MAXBETS];
int bets[MAXN];
int N;

int main(void) {
    scanf("%d", &N);
    int i = 0;
    for(i = 0; i < N; ++i) {
        scanf("%d", &bets[i]);
        counts[bets[i]]++;
    }
    int found = 0;
    for(i = 0; i < N; ++i) {
        if(1 == counts[bets[i]])
        {
            printf("%d\n", bets[i]);
            found = 1;
            break;
        }
    }
    if(!found) printf("None\n");
    return 0;
}
