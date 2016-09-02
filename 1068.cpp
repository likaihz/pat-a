#include<cstdio>
#include<algorithm>

#define MAXN 10001
#define MAXV 101
using namespace std;

int w[MAXN], dp[MAXV] = {0};
bool choice[MAXN][MAXV], flag[MAXN];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++)
        scanf("%d", &w[i]);
    sort(w+1, w+n+1, cmp);
    for(int i = 1; i <= n; i++)
        for(int v = m; v >= w[i]; v--)
        {
            if(dp[v] <= dp[v - w[i]] + w[i])
            {
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = true;
            }
            else choice[i][v] = false;
        }
    if(dp[m] != m) printf("No Solution\n");
    else
    {
        int k = n, num = 0, v = m;
        while(k >= 0)
        {
            if(choice[k][v] == true)
            {
                flag[k] = true;
                v -= w[k];
                num++;
            }
            else flag[k] = false;
            k--;
        }
        for(int i = n; i >= 1; i--)
        {
            if(flag[i] == true){
                printf("%d", w[i]);
                num--;
                if(num > 0) printf(" ");
            }
        }
        //printf("\n");
    }
    return 0;
}
