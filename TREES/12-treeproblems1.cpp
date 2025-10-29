#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
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

//two trees are identical
bool identicalTreesOrNot(Node* root1, Node* root2){
    if(!root1 && !root2) return true;
    if(!root1 && root2) return false;
    if(!root2 && root1) return false;
    if(root1-> data != root2->data) return false; 
    return (identicalTreesOrNot(root1->left, root2->left) && 
    identicalTreesOrNot(root1->right, root2->right));
}

//subtree of another tree
bool isIdentical(Node* root, Node* subroot){
    if(root == NULL || subroot == NULL) return root == subroot;
    return (root->data == subroot->data && isIdentical(root->left, subroot->left) 
    && isIdentical(root->right, subroot->right));
}
bool isSubtree(Node* root, Node* subroot){
    if(root == NULL || subroot == NULL) return root == subroot;
    if(root->data == subroot->data && isIdentical(root, subroot)){
        return true;
    }
    return (isSubtree(root->left, subroot) || isSubtree(root->right, subroot));
}

//given a BT, convert it to its mirror image form
void mirrorOfBT(Node* root){
    if(root == NULL) return;
    Node* temp = root;
    root->left = temp->right;
    root->right = temp->left;
    mirrorOfBT(root->left);
    mirrorOfBT(root->right);
}

//check for balance tree
//condition for balance tree (-1 <= height(left subtree)-height(right subtree) <= 1)
int heightOfBT(Node* root, bool valid){
    if(root == NULL) return 0;
    int l = heightOfBT(root->left, valid);
    int r = heightOfBT(root->right, valid);
    if(abs(l-r) > 1) valid = false;
    return 1 + max(l,r);
}
bool isBalanceTree(Node* root){
    bool valid = true;
    heightOfBT(root, valid);
    return valid;
}

//or

int checkHeight(Node* root){
    if(root == NULL) return 0;
    int leftHeight = checkHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight-rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalancedTree(Node* root){
    return checkHeight(root) != -1;
}

//check if 2 nodes are cousins
// cousins conditions: same level & different parent
bool isCousins(Node* root, int x, int y){
    if(root == NULL) return false;
    queue<pair<Node*, Node*>> que;
    que.push({root, NULL});
    while(!que.empty()){
        int size = que.size();
        Node* xParent = NULL;
        Node* yParent = NULL;
        while(size--){
            auto temp = que.front();
            que.pop();
            Node* node = temp.first;
            Node* parent = temp.second;
            if(node->data == x) xParent = parent;
            if(node->data == y) yParent = parent;
            if(node->left) que.push({node->left, node});
            if(node->right) que.push({node->right, node});
        }
        if(xParent && yParent){
            return xParent != yParent;
        }
        if((xParent && !yParent) || (yParent && !xParent)){
            return false;
        }
    }
    return false;
}

// maximum path sum
