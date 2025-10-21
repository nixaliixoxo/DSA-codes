#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left=right=NULL;
    }
};

void cntNonLeafNodes(Node* root, int& cnt){
    if(root == NULL) return;
    if(root-> left || root->right) cnt++;
    cntNonLeafNodes(root->left, cnt);
    cntNonLeafNodes(root->right, cnt);
}

int cntNonLeafNodes2(Node* root){
    if(root == NULL) return 0;
    if(!root->right && !root->left) return 0;
    int cnt = 1 + cntNonLeafNodes2(root->left) + cntNonLeafNodes2(root->right);
    return cnt;
}