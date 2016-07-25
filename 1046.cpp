#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dis[n+2];
    dis[0] = 0;
    int total = 0;
    int t;
    for(int i = 1; i < n; i++){
        cin >> t;
        dis[i] = t + dis[i-1];
        total += t;
    }
    cin >> t ;
    total += t;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int h,r;
        int dis1, dis2;
        cin >> h >> r;
        h--, r--;
        dis1 = abs(dis[h] - dis[r]);
        dis2 = total - dis1;

        cout << ((dis1 < dis2)?dis1:dis2) << endl;
        
    }    
}
