// LEVEL ORDER OR BFS TRAVERSAL

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

//spiral form level order traversal
vector<int> spiralLevelOrder(Node* root){
    stack <Node*> s1; //right to left
    stack <Node*> s2; //left to right
    s1.push(root);
    vector<int> ans;
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                Node* temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if(temp->right) s2.push(temp->right);
                if(temp->left) s2.push(temp->left);
            }
        }
        else{
            while(!s2.empty()){
                Node* temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                if(temp->left) s1.push(temp->left);
                if(temp->right) s1.push(temp->right);
            }
        }
    }
    return ans;
}

//or

vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> que;
    que.push(root);
    bool leftToRight = true;
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        while(size--){
            Node* node = que.front();
            que.pop();
            vec.push_back(node->data);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        if(!leftToRight){
            reverse(vec.begin(), vec.end());
        }
        ans.push_back(vec);
        leftToRight = !leftToRight;
    }
    return ans;
}

//level order or BFS N-ary tree

// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// class Node{
//     public:
//     int data;
//     vector<Node*> children;
//     Node(int value){
//         data = value;
//     }
//     Node(int value, vector<Node*> children_){
//         data = value;
//         children = children_;
//     }
// };

// vector<vector<int>> levelOrderTraversal4(Node* root){
//     vector<vector<int>> ans;
//     if(root == NULL) return ans;
//     queue <Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         int size = q.size();
//         vector<int> level;
//         while(size--){
//             Node* temp = q.front();
//             q.pop();
//             level.push_back(temp->data);
//             for(Node* child: temp->children){
//                 q.push(child);
//             }
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }


 