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

int heightofBT(Node* root){
    if(root == NULL) return 0;
    int height = 1 + max(heightofBT(root->left), heightofBT(root->right));
    return height;
}

int cntNodesOfBT(Node* root){
    if(root == NULL) return 0;
    return 1 + cntNodesOfBT(root->left) + cntNodesOfBT(root->right);
}

int sumOfNodesOfBT(Node* root){
    if(root == NULL) return 0;
    return root->data + sumOfNodesOfBT(root->left) + sumOfNodesOfBT(root->right);
}

int diameterofBT(Node* root, int& result){ //result = 0
    if(root == NULL) return 0;
    int left = diameterofBT(root->left, result);
    int right = diameterofBT(root->right, result);
    result = max(result, left + right);
    return 1 + max(left, right);
}

