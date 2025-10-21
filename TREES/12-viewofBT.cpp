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

// left view of BT
vector<int> leftView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        ans.push_back(que.front()->data);
        while(size--){
            Node* temp = que.front();
            que.pop();
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
    }
    return ans;
}

// using recursion
void leftView2(Node* root, int level, vector<int>& ans){
    if(root == NULL) return;
    if(level == ans.size()) ans.push_back(root->data);
    leftView2(root->left, level+1, ans);
    leftView2(root->right, level+1, ans);
}

// right view
vector<int> rightView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        ans.push_back(que.front()->data);
        while(size--){
            Node* temp = que.front();
            que.pop();
            if(temp->right) que.push(temp->right);
            if(temp->left) que.push(temp->left);
        }
    }
    return ans;
}

void rightView2(Node* root, int level, vector<int>& ans){
    if(root == NULL) return;
    if(level == ans.size()) ans.push_back(root->data);
    rightView2(root->right, level+1, ans);
    rightView2(root->left, level+1, ans);
}

// top view
void findExtremes(Node* root, int pos, int& l, int& r){
    if(!root) return;
    l = min(l, pos);
    r = max(r, pos);
    findExtremes(root->left, pos-1, l, r);
    findExtremes(root->right, pos+1, l, r);
}
vector<int> topView(Node* root){
    int l=0, r=0;
    findExtremes(root, 0, l, r);
    vector<int> ans(r-l+1);
    vector<bool> filled(r-l+1);
    queue<pair<Node*, int>> que;
    que.push({root, -1*l});
    while(!que.empty()){
        auto temp = que.front();
        que.pop();
        Node* node = temp.first;
        int pos = temp.second;
        if(!filled[pos]){
            ans[pos] = node->data;
            filled[pos] = true;
        }
        if(node->left){
            que.push({node->left, pos-1});
        }
        if(node->right){
            que.push({node->right, pos+1});
        }
    }
    return ans;
}

// using recursion
void topViewHelper(Node* root, int pos, int lvl, vector<int>& ans, vector<int>& level){
    if(level[pos] > lvl){
        ans[pos] = root->data;
        level[pos] = lvl;
    }
    topViewHelper(root->left, pos-1, lvl+1, ans, level);
    topViewHelper(root->right, pos+1, lvl+1, ans, level);
}
vector<int> topView2(Node* root){
    int l=0, r=0;
    findExtremes(root, 0, l, r);
    vector<int> ans(r-l+1);
    vector<int> level(r-l+1, INT64_MAX);
    topViewHelper(root, -1*l, 0, ans, level);
    return ans;
}

