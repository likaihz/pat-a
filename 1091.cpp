#include<iostream>
#include<queue>

using namespace std;
class Position{
public:
    int i, j, k;
} pos;

int M, N, L, T;
int pxl[1287][129][61];
bool visited[1287][129][61] = {false};
int I[6] = {0, 0, 0, 0, 1, -1};
int J[6] = {0, 0, 1, -1, 0, 0};
int K[6] = {1, -1, 0, 0, 0, 0};

bool judge(int i, int j, int k)
{
    if(i >= M || i < 0 || j >= N || j < 0 || k >= L || k < 0 ) return false;
    if(visited[i][j][k] || pxl[i][j][k] == 0) return false;
    return true;
}

int BFS(int i, int j, int k)
{
    int cnt = 0;
    queue<Position> Q;
    
    pos.i = i, pos.j = j, pos.k = k;
    Q.push(pos);
    visited[i][j][k] = true;
    while(!Q.empty())
    {
        Position front = Q.front();
        Q.pop();
        cnt++;
        for(int i = 0; i < 6; i++)
        {
            int newI = front.i + I[i];
            int newJ = front.j + J[i];
            int newK = front.k + K[i];

            if(judge(newI, newJ, newK))
            {
                pos.i = newI, pos.j = newJ, pos.k = newK;
                Q.push(pos);
                visited[newI][newJ][newK] = true;
            }
        }
    }
    if(cnt >= T) return cnt;
    else return 0;
    
}
int main()
{
    cin >> M >> N >> L >> T;
    for(int k = 0; k < L; k++)
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                cin >> pxl[i][j][k];
    int cnt = 0;
    for(int k = 0; k < L; k++)
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                if(pxl[i][j][k] == 1 && visited[i][j][k] == false)
                    cnt += BFS(i, j, k);

    cout << cnt << endl;
    return 0;
}
