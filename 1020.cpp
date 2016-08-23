#include<iostream>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};
int N;
int PostOdr[30], InOdr[30];
Node* create(int l1, int r1, int l2, int r2)
{
    int root_idx;
    if(l1 > r1) return NULL;
    for(int i = l2; i <= r2; i++)
        if(InOdr[i] == PostOdr[r1])
        {
            root_idx = i;
            break;
        }
    Node* root = new Node();
    int numLeft = root_idx-l2;
    root -> data = PostOdr[r1];
    root -> left = create(l1, l1+numLeft-1, l2, root_idx-1);
    root -> right = create(l1+numLeft, r1-1, root_idx+1, r2);
    return root;

}

int main()
{
    queue<Node*> Q;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> PostOdr[i];
    for(int i = 0; i < N; i++)
        cin >> InOdr[i];
    Node *tree = create(0, N-1, 0, N-1);
    if(tree != NULL)cout << tree -> data;
    if(tree->left != NULL) Q.push(tree->left);
    if(tree->right != NULL) Q.push(tree->right);
    while(!Q.empty())
    {
        Node * node = Q.front();
        cout << " " << node -> data;
        if(node->left != NULL) Q.push(node->left);
        if(node->right != NULL) Q.push(node->right);
        Q.pop();
    }

    cout << endl;
    return 0;
}
