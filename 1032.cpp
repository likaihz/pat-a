#include<cstdio>
#include<iostream>
#include<unordered_set>
using namespace std;

class Node{
public:
    int  nxt;
    bool visited;
} node[100001];
int main()
{
    int head1, head2, n, res = -1;
    cin >> head1 >> head2 >> n;
    for(int i = 0; i < n; i++)
    {
        int ptr, nxt;
        char c;
        cin >> ptr >> c >> nxt;
        node[ptr].nxt = nxt;
        node[ptr].visited = false;
    }
    int nxt = head1, crt;
    while(nxt != -1)
    {
        crt = nxt;
        node[crt].visited = true;
        nxt = node[crt].nxt;
    }
    nxt = head2;
    while(nxt != -1)
    {
        crt = nxt;
        if(node[crt].visited){
            res = crt;
            break;
        }
        else nxt = node[crt].nxt;
    }

    if(res == -1) cout << res << endl;
    else printf("%05d\n", res);
    return 0;      
}
