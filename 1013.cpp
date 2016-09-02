#include<iostream>
#include<vector>

using namespace std;

int N, M;
int lost_city, block = 0;
vector<int> cities[1001];
bool visited[1001] = {false};
void DFS(int city)
{
    visited[city] = true;
    for(auto it = cities[city].begin(); it != cities[city].end(); it++)
        if(*it != lost_city && !visited[*it])
            DFS(*it);
}
int main()
{
    int K;
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        cities[c1].push_back(c2);
        cities[c2].push_back(c1);
    }

    for(int i = 0; i < K; i++)
    {
        cin >> lost_city;
        block = 0;
        for(int j = 1; j <= N; j++) visited[j] = false;
        for(int j = 1; j <= N; j++)
        {
            if(j == lost_city) continue;
            if(!visited[j])
            {
                block++;
                DFS(j);
            }
        }
        cout << block-1 <<endl;
    }
    return 0;
}
