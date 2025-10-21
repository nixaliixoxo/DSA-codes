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