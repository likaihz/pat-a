#include<algorithm>
#include<iostream>
#include<map>
#include<vector>

using namespace std;
map<string, vector<string> > Adj_list;
map<string, int> weight;
map<string, bool> visited;
map<string, int> res;
int N, K;
int cnt, total;
string head;

void DFS(string name)
{
    visited[name] = true;
    cnt += 1;
    total += weight[name];
    if(weight[name] > weight[head] ) head = name;
    for(auto it = Adj_list[name].begin(); it != Adj_list[name].end(); it++)
        if(!visited[*it]) DFS(*it);
}
int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        string name1, name2;
        int call;
        cin >> name1 >> name2 >> call;
        Adj_list[name1].push_back(name2);
        Adj_list[name2].push_back(name1);
        weight[name1] += call;
        weight[name2] += call;
        visited[name1] = false;
        visited[name2] = false;
    }
    for(auto it = visited.begin(); it != visited.end(); it++)
    {
        if(!(it -> second))
        {
            cnt = 0;
            total = 0;
            head = it -> first;
            DFS(head);
            if(cnt > 2 && total/2 > K) res[head] = cnt;
        }
    }
    cout << res.size() << endl;
    for(auto it = res.begin(); it != res.end(); it++)
        cout << it -> first << ' ' << it->second << endl;
    
    return 0;
}
