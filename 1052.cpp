#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int Address, Key, Next;
} buf[100001];

bool cmp(Node& a, Node& b)
{
    return a.Key < b.Key;
}
int main()
 {
    int n, head;
    vector<Node> vec;
    cin >> n >> head;
    for(int i = 0; i < n; i++)
    {
        int ptr, data, nxt;
        cin >> ptr >> data >> nxt;
        buf[ptr].Address = ptr;
        buf[ptr].Key = data;
        buf[ptr].Next = nxt;
    }
    int crt = head;
    while(crt != -1)
    {
        vec.push_back(buf[crt]);
        crt = buf[crt].Next;
    }
    if(vec.size() != 0){
        sort(vec.begin(), vec.end(), cmp);
        for(auto it = vec.begin(); it != vec.end()-1; it++)
            it -> Next = (it+1) -> Address;
        (vec.end()-1) -> Next = -1;
        printf("%d %05d\n", vec.size(), vec.begin() -> Address);
        for(auto it = vec.begin(); it != vec.end()-1; it++)
            printf("%05d %d %05d\n", it->Address, it->Key, it->Next);
        printf("%05d %d -1\n", (vec.end()-1)->Address, (vec.end()-1)->Key);
    }
    else cout << "0 -1" <<endl;
    return 0;
}
