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

void sumofBT(Node* root, int& sum){
    if(root == NULL) return;
    sum += root->data;
    sumofBT(root->left, sum);
    sumofBT(root->right, sum);
}

int sumofBT2(Node* root){
    if(root == NULL) return 0;
    return (root->data + sumofBT2(root->right) + sumofBT2(root->left));
}