#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int N, minLvl = 100001, cnt = 0;
double P, r;
vector<int> Node[100000];
void DFS(int idx, int level)
{
    if(Node[idx].empty())
    {
        if(level == minLvl) cnt++;
        if(level < minLvl) minLvl = level, cnt = 1;
        return;
    }

    for(auto it = Node[idx].begin(); it != Node[idx].end(); it++)
        DFS(*it, level+1);
}
int main()
{
    cin >> N >> P >> r;
    for(int i = 0; i < N; i++)
    {
        int k, id;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> id;
            Node[i].push_back(id);
        }
    }
    DFS(0,0);
    printf("%.4f %d\n", P*pow(1.0+r/100.0, minLvl), cnt);
    return 0;
}
