//PREORDER -> MLR (node, left, right)

#include <iostream>
#include <queue>
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

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data;
}

void inorder(Node* root){
    if(root == NULL) return;
    preorder(root->left);
    cout << root->data;
    preorder(root->right);
}

Node* BinaryTree(){
    int x;
    cin >> x;
    if(x == -1){
        return NULL;
    }
    Node* temp = new Node(x);
    temp->left = BinaryTree();
    temp->right = BinaryTree();
    return temp;
}

int main(){
    Node* root = BinaryTree();
    preorder(root);
    postorder(root);
    inorder(root);
}

// TC -> O(N)
// SC -> O(h) & O(N) in worst case
