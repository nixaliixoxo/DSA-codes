//level order or BFS N-ary tree

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
    Node(int value){
        data = value;
    }
    Node(int value, vector<Node*> children_){
        data = value;
        children = children_;
    }
};

vector<vector<int>> levelOrderTraversal4(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        while(size--){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            for(Node* child: temp->children){
                q.push(child);
            }
        }
        ans.push_back(level);
    }
    return ans;
}