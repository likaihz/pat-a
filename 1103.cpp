#include<cmath>
#include<iostream>
#include<vector>

using namespace std;
int N, K, P;
int maxFacSum = -1;
vector<int> Pow, res, temp;
void Init()
{
    int tmp = 0, i = 0;
    while(tmp <= N)
    {
        Pow.push_back(tmp);
        tmp = pow(++i, P);
    }
}
void DFS(int index, int CntFac, int CrtSum, int facSum)
{
    if(CrtSum == N && CntFac == K )
    {
        if(facSum > maxFacSum)
        {
            res = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if(CrtSum > N || CntFac > K) return;
    if(index > 0){
        temp.push_back(index);
        DFS(index, CntFac+1, CrtSum+Pow[index], facSum+index);
        temp.pop_back();
        DFS(index-1, CntFac, CrtSum, facSum);
    }
}
int main()
{
    cin >> N >> K >>P;

    Init();
    DFS(Pow.size()-1, 0, 0, 0);
    if(maxFacSum == -1) cout << "Impossible" << endl;
    else
    {
        cout << N << " = " << res[0] << '^' << P;
        for(int i = 1; i < res.size(); i++)
        {
            cout << " + " << res[i] << '^' << P;
        }
        cout << endl;
    }
    return 0;
}
