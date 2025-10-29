#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
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

// vertical order traversal
vector<int> vertical(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> que;
    que.push({root, 0});
    while(!que.empty()){
        auto temp = que.front();
        que.pop();
        Node* node = temp.first;
        int pos = temp.second;
        mp[pos].push_back(node->data);
        if(node->left) que.push({node->left, pos-1});
        if(node->right) que.push({node->right, pos+1});
    }
    for(auto it: mp){
        for(auto x: it.second){
            ans.push_back(x);
        }
    }
    return ans;
}

// diagonal traversal (if two nodes are on same vertical and same level first nodes of left subtree
// need to be processed then right subtree)
int findLeftMostNodePos(Node* root, int pos){
    if(root == NULL) return;
    int leftmostpos = max(leftmostpos, pos);
    findLeftMostNodePos(root->left, pos+1);
    findLeftMostNodePos(root->right, pos);
    return leftmostpos;
}
void diagonalHelper(Node* root, int pos, vector<vector<int>>& temp){
    if(root == NULL) return;
    temp[pos].push_back(root->data);
    diagonalHelper(root->left, pos+1, temp);
    diagonalHelper(root->right, pos, temp);
}
vector<int> diagonal(Node* root){
    int leftMostPos = findLeftMostNodePos(root, 0);
    vector<vector<int>> temp(leftMostPos+1);
    diagonalHelper(root, 0, temp);
    vector<int> ans;
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            ans.push_back(temp[i][j]);
        }
    }
    return ans;
}

// boundary traversal
void leftBoundary(Node* root, vector<int>& ans){
    if(!root || (!root->left && !root->right)) return;
    ans.push_back(root->data);
    if(root->left) leftBoundary(root->left, ans);
    else if(root->right) leftBoundary(root->right, ans);
}
void rightBoundary(Node* root, vector<int>& ans){
    if(!root || (!root->left && !root->right)) return;
    if(root->right) rightBoundary(root->left, ans);
    else if(root->left) rightBoundary(root->right, ans);
    ans.push_back(root->data); //isme insert baad me kra hai return hote time taki reverse me store ho
}
void leafNodes(Node* root, vector<int>& ans){
    if(root == NULL) return;
    if(!root->left && !root->right) ans.push_back(root->data);
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}
vector<int> boundary(Node* root){
    if(root == NULL) return;
    vector<int> ans;
    ans.push_back(root->data);
    if(root->left) leftBoundary(root->left, ans);
    if(root->left || root->right) leafNodes(root, ans); 
    if(root->right) rightBoundary(root->right, ans);
    return ans;
}

