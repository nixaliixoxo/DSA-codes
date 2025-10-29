//PREORDER -> MLR (node, left, right)

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

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

vector<int> preorderIterative(Node* root){
    vector<int> preorder;
    if(root == NULL) return preorder;
    stack <Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
    return preorder;
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

vector<int> postorderIterative(Node* root){
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<Node*> st;
    Node* curr = root;
    while(!st.empty() || curr != NULL){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            } else{
                curr = temp;
            }
        }
    }
    return postorder;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

vector<int> inorderIterative(Node* root){
    vector<int> inorder;
    if(root == NULL) return inorder;
    Node* node = root;
    stack<Node*> st;
    while(!st.empty() || node != NULL){
        if(node != NULL){
            st.push(node);
            node = node->left;
        } 
        else{
            if(!st.empty()){
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
    }
    return inorder;
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

//INORDER MORRIS TRAVERSAL
vector<int> inOrder(Node* root) {
    vector<int> ans;
    while(root){
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }
        else{
            Node* curr = root->left;
            while(curr->right && curr->right != root){
                curr = curr->right;
            }
            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            } else{
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }
    return ans;
}

//PREORDER MORRIS TRAVERSAL
vector<int> preOrder(Node* root) {
    vector<int> ans;
    while(root){
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        } else{
            Node* curr = root->left;
            while(curr->right && curr->right != root){
                curr = curr->right;
            }
            if(curr->right == NULL){
                ans.push_back(root->data);
                curr->right = root;
                root = root->left;
            } else{
                curr->right = NULL;
                root = root->right;
            }
        }
    }
    return ans;
}

//POSTORDER MORRIS TRAVERSAL
//LRN -> revrse (NRL)
