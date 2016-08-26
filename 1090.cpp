#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>

#define MAXN 100000

using namespace std;
int N, root, deepest = -1, cnt = 0;
double P,r;
vector<int> Node[MAXN];

void DFS(int index, int crtDepth)
{
    if(Node[index].empty())
    {
        if(crtDepth == deepest) cnt++;
        if(crtDepth > deepest) deepest = crtDepth, cnt = 1;
        return;
    }

    for(auto it = Node[index].begin(); it != Node[index].end(); it++)
        DFS(*it, crtDepth+1);
}
int main()
{
    cin >> N >>P >> r;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp < 0) root = i;
        else Node[tmp].push_back(i);
    }
    DFS(root, 0);

    double highest = P * pow(1.0+r/100.0, deepest);
    printf("%.2f %d\n", highest, cnt);
    return 0;
}
