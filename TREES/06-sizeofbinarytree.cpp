//size of BT means total no of nodes in BT

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

void sizeofBT(Node* root, int& cnt){
    if(root == NULL) return;
    cnt++;
    sizeofBT(root->left, cnt);
    sizeofBT(root->right, cnt);
}

int sizeofBT2(Node* root){
    if(root == NULL) return 0;
    return (1 + sizeofBT2(root->left) + sizeofBT2(root->right));
}
