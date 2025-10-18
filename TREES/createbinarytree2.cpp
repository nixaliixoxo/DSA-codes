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
    Node* root;
    root = BinaryTree();
}

// TC -> O(N)
// SC -> O(h) where h is height of tree and this height actually tells max kitna stack bhra tha
// SC -> O(N) worst case
