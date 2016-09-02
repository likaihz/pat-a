#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    vector<int> childern;
    int level;
} node[100];
int N, M;
void Travel(int idx, int lvl)
{
    node[idx].level = lvl;
    if(node[idx].childern.empty()) return;

    for(auto it = node[idx].childern.begin(); it != node[idx].childern.end(); it++)
    {
        Travel(*it, lvl+1);
    }
}

int main()
{
    cin >> N >> M;
    int cnt[100] = {0};
    int gen = 1, max;
    for(int i = 0; i < M; i++)
    {
        int id, k;
        cin >> id >> k;
        for(int j = 0; j < k; j++)
        {
            int tmp;
            cin >> tmp;
            node[id].childern.push_back(tmp);
        }
    }

    Travel(1, 1);

    for(int i = 1; i <= N; i++)
        cnt[node[i].level]++;
    max = cnt[1];
    for(int i = 2; i <= N; i++)
        if(cnt[i] > max)
            max = cnt[i], gen = i;

    cout << max << ' ' << gen << endl;
    
    return 0;
}
