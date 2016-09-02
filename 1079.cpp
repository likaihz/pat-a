#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#define MAXN 100000

using namespace std;
vector<int> Node[MAXN];
map<int, int> leaves;
int N;
double P, r, total = 0;
void DFS(int idx, int depth)
{
    if(Node[idx].empty()){
        total += P*pow(1.0+r/100.0, depth)*leaves[idx];
        return;
    }
    for(auto it = Node[idx].begin(); it != Node[idx].end(); it++)
        DFS(*it, depth+1);

    return;
    
}
int main()
{
    bool isChild[MAXN] = {false};
    int root;
    cin >> N >> P >> r;
    for(int i = 0; i < N; i++)
    {
        int k, id;
        cin >> k;
        if(k != 0)
            for(int j = 0; j < k; j++)
            {
                cin >> id;
                Node[i].push_back(id);
                isChild[id] = true;
            }
        else {
            cin >> id;
            leaves[i] = id;
        }
        for(int i = 0; i < N; i++)
            if(!isChild[i])
            {
                root = i;
                break;
            }
    }

    DFS(root, 0);
    printf("%.1f\n", total);
    return 0;
}
