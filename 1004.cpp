#include<iostream>
#include<vector>
using namespace std;
vector<int> Node[100];

int M, N;
int cnt[100] = {0};
int deepest = 0;
void Travel(int idx, int lvl)
{
    if(lvl > deepest) deepest = lvl;
    if(Node[idx].empty())
    {
        cnt[lvl]++;
        return;
    }
    for(auto it = Node[idx].begin(); it != Node[idx].end(); it++)
        Travel(*it, lvl+1);
}
int main()
{
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int id, k;
        cin >> id >> k;
        for(int j = 0; j < k; j++)
        {
            int tmp;
            cin >> tmp;
            Node[id].push_back(tmp);
        }
    }
    Travel(1, 0);
    cout << cnt[0];
    for(int i = 1; i <= deepest; i++)
        cout << ' '<< cnt[i];
    cout <<endl;
    return 0;
}
