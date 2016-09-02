#include<iostream>
using namespace std;


int main()
{
    int N, M, L;
    int EVA[201] = {0}, GIVEN[100000], dp[100000] = {0};
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int tmp;
        cin >> tmp;
        EVA[tmp] = i;;
    }
    cin >> L;
    for(int i = 0; i < L; i++)
        cin >> GIVEN[i];
    int max = 0;
    if(EVA[GIVEN[0]] != 0) dp[0] = 1, max = 1;
    for(int i = 1; i < L; i++)
    {
        if(EVA[GIVEN[i]] != 0)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(EVA[GIVEN[j]] <= EVA[GIVEN[i]] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] +1;
            }
            if(dp[i] > max) max = dp[i];
        }
    }
    cout << max << endl;
    
    return 0;
}
