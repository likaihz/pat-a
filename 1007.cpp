#include<iostream>
#define MAX 10000
using namespace std;

int main()
{
    int k;
    int num[MAX], dp[MAX];
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> num[i];
    dp[0] = num[0];
    int max = dp[0], front_t = num[0], end_t = num[0], front = num[0], end = num[0];
    for(int i = 1; i < k; i++)
    {
        if(num[i] > num[i]+dp[i-1])
            dp[i] = num[i], front_t = num[i];
        else
            dp[i] = num[i]+dp[i-1];
        end_t = num[i];
        if(dp[i] > max)
            front = front_t, end = end_t, max = dp[i];
    }
    if(max >= 0)
        cout << max << ' ' << front << ' ' << end << endl;
    else
        cout << 0 << ' ' <<  num[0] << ' ' << num[k-1] << endl;
    return 0;
}
