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

void cntLeaves(Node* root, int& cnt){
    if(root == NULL) return;
    if(!root->left && !root->right){
        cnt++;
        return;
    }
    cntLeaves(root->left, cnt);
    cntLeaves(root->right, cnt);
}

int cntLeaves2(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int cnt = cntLeaves2(root->left) + cntLeaves2(root->right);
    return cnt;
}