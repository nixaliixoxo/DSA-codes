// LEVEL ORDER OR BFS TRAVERSAL

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

void levelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue <Node* > q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left){
            q.push(temp->left);
        } 
        if(temp->right){
            q.push(temp->right);
        }
    }
}

// TC -> O(N)
// SC -> O(N/2+1) i.e. n/2+1 are leaf nodes for perfect binary tree and theseorm max space in the queue
// SC -> O(N) in worst case

//level wise printing
void levelOrderTraversal2(Node* root){
    if(root == NULL) return;
    queue <Node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } 
        else{
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void reverseLevelorderTraversal(Node* root){
    if(!root) return;
    queue <Node*> q;
    stack <Node*> st;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        st.push(temp);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    while(!st.empty()){
        cout << st.top()->data << " ";
        st.pop();
    }
}

// returning vector<vector<int> level wise
vector<vector<int>> levelOrderTraversal3(Node* root){
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
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(level);
    }
    return ans;
}


 