//简单并查集问题
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int N;
int hobby_cluster[1001];   //将兴趣分成集合，值表示根
int person[1001];    //用兴趣集的根表示一个人所在的集合
int findRoot(int i)
{
    if(hobby_cluster[i] == i) return i;

    int root = findRoot(hobby_cluster[i]);
    hobby_cluster[i] = root;
    return root;
}

void Union(int a, int b)
{
    int root_a = findRoot(a);
    int root_b = findRoot(b);

    hobby_cluster[root_b] = root_a;
    
}
bool cmp(int a, int b)
{
    return a >= b;
}
int main()
{
    cin >> N;
    for(int i = 0; i <= 1000; i++) hobby_cluster[i] = i;
    for(int i = 1; i <= N; i++)
    {
        int K, hobby0;
        cin >> K;
        getchar();
        cin >> hobby0;
        for(int j = 1; j < K; j++)
        {
            int tmp;
            cin >> tmp;
            Union(hobby0, tmp);
        }
        person[i] = findRoot(hobby0);
    }

    map<int, int> record;
    for(int i = 1; i <= N; i++) person[i] = findRoot(person[i]);
    for(int i = 1; i <= N; i++)
        record[person[i]] ++;
    vector<int> cnt;
    for(auto it = record.begin(); it != record.end(); it++)
        cnt.push_back(it -> second);
    cout << cnt.size() << endl;
    sort(cnt.begin(), cnt.end(), cmp);
    cout << *(cnt.begin());
    for(auto it = ++cnt.begin(); it != cnt.end(); it++)
        cout << ' '<< *it;
    cout << endl;
    return 0;
}
