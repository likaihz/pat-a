#include<iostream>
#include<sstream>
#include<stack>
#include<vector>

using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* righht;
};
vector<int> inOrdr, preOrdr, postOrdr;

int getnum(string s)
{
    stringstream ss;
    int res;
    ss << s.substr(5);
    ss >> res;
    return res;
}

Node* create(int inL, int inR, int preL, int preR)
{
    if(inL > inR) return NULL;
    int root_idx = inL;
    for(;root_idx<inR; root_idx++)
        if(inOrdr[root_idx] == preOrdr[preL]) break;
    int numL = root_idx - inL;
    Node* root = new Node();
    root -> data = inOrdr[root_idx];

    root -> left = create(inL, root_idx-1, preL+1, preL+numL);
    root -> righht = create(root_idx+1, inR, preL+numL+1, preR);
    return root;
}

void PostOrderTravel(Node * node)
{
    if(node == NULL) return;

    PostOrderTravel(node->left);
    PostOrderTravel(node->righht);

    postOrdr.push_back(node->data);
    return;
}
int main()
{
    int N;
    string in;
    stack<int> s;
    cin >> N;
    getline(cin, in);
    for(int i = 0; i < 2*N; i++)
    {
        getline(cin,in);
        if(in[1] == 'o'){
            int tmp = s.top();
            s.pop();
            inOrdr.push_back(tmp);
        }
        if(in[1] == 'u'){
            int tmp = getnum(in);
            s.push(tmp);
            preOrdr.push_back(tmp);
        }
    }s

    Node* tree = create(0, N-1, 0, N-1);
    PostOrderTravel(tree);
    cout <<*(postOrdr.begin()) ;
    for(auto it = postOrdr.begin()+1; it != postOrdr.end(); it++)
        cout << ' ' << *it;
    cout << endl;
    return 0;
}
