#include<iosrteam>

using namespace std;
int N, M, S;
int weight[101];
vector<int> Node[100];
int main()
{
    cin >> N >> M >> S;
    for(int i = 0; i < N; i++)
    {
        int w; 
        cin >> w;
        weight[i] = w;
    }
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
    

    return 0;
}
