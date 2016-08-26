#include<iostream>
#include<queue>
#include<vector>
#define MAXN 10

using namespace std;

class Node{
public:
    int left, right;
} node[MAXN];
vector<int> inOrder;
int N, root;
void inOrderTravel(int n)
{
    if(n == -1) return;
    inOrderTravel(node[n].left);
    inOrder.push_back(n);
    inOrderTravel(node[n].right);
    return;
    
}
int main()
{
    
    queue<int> Q;
    bool isChild[MAXN]={false};
    string ln;
    cin >> N;
    getline(cin, ln);
    for(int i = 0; i < N; i++)
    {
        getline(cin, ln);
        if(ln[0] == '-') node[i].right = -1;
        else {
            node[i].right = ln[0]-'0';
            isChild[ln[0]-'0'] = true;
        }
        if(ln[2] == '-') node[i].left = -1;
        else {
            node[i].left = ln[2]-'0';
            isChild[ln[2]-'0'] = true;
        }
    }
    for(int i = 0; i < N; i++)
        if(!isChild[i]) root = i;
    cout << root;
    if(node[root].left != -1) Q.push(node[root].left);
    if(node[root].right != -1) Q.push(node[root].right);
    while(!Q.empty())
    {
        int front = Q.front();
        cout << ' ' << front;
        if(node[front].left != -1) Q.push(node[front].left);
        if(node[front].right != -1) Q.push(node[front].right);
        Q.pop();
    }
    cout << endl;

    inOrderTravel(root);
    cout << inOrder[0];
    for(int i = 1; i < N; i++)
        cout << ' ' << inOrder[i];
    cout << endl;
    return 0;
}
