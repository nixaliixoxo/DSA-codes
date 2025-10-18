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

int main(){
    int x;
    cin >> x;
    int firstChild, secondChild;
    queue <Node*> q;
    Node* root = new Node(x);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cin >> firstChild;
        if(firstChild != -1){
            temp->left = new Node(firstChild);
            q.push(temp->left);
        }
        cin >> secondChild;
        if(secondChild != -1){
            temp->right = new Node(secondChild);
            q.push(temp->right);
        }
    }
}