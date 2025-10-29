// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//CONSTRUCT BINARY TREE FROM PREORDER AND INORDER - LC 105
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int i = inStart;
    for(; i<=inEnd; i++){
        if(preorder[preStart] == inorder[i]) break;
    }
    int leftSize = i-inStart;
    int rightSize = inEnd-i;
    root->left = buildTree(preorder, inorder, preStart+1, preStart+leftSize, inStart, i-1);
    root->right = buildTree(preorder, inorder, preEnd-rightSize+1, preEnd, i+1, inEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    return root;
}

//CONSTRUCT BINARY TREE FROM INORDER AND POSTORDER - LC 106
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
    if((inStart > inEnd) || (postStart > postEnd)) return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int i = inStart;
    for(; i<=inEnd; i++){
        if(postorder[postEnd] == inorder[i]) break;
    }
    int leftSize = i-inStart;
    int rightSize = inEnd-i;
    root->left = buildTree(inorder, postorder, inStart, i-1, postStart, postStart+leftSize-1);
    root->right = buildTree(inorder, postorder, i+1, inEnd, postEnd-rightSize, postEnd-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* root = buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    return root;
}

//CONSTRUCT BINARY TREE FROM PREORDER AND POSTORDER - LC 889
TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd, unordered_map<int,int>& mp){
    if(preStart > preEnd || postStart > postEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    if(preStart == preEnd) return root;
    int leftSubtreeKaRoot = preorder[preStart+1];
    // int j = postStart;
    // while(j <= postEnd && postorder[j] != leftSubtreeKaRoot){
    //     j++;
    // } this while loop was taking another O(N) so we use map to store and fetch index of value from postorder since all elements are distinct as said in the problem
    int j = mp[leftSubtreeKaRoot]; 
    int num = j-postStart+1;
    root->left = buildTree(preorder, postorder, preStart+1, preStart+num, postStart, j, mp);
    root->right = buildTree(preorder,postorder, preStart+num+1, preEnd, j+1, postEnd, mp);
    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    unordered_map<int,int> mp;
    for(int i=0; i<postorder.size(); i++){
        mp[postorder[i]] = i;
    }
    TreeNode* root = buildTree(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1, mp);
    return root;
}

//CONSTRUCT FULL BINARY TREE FROM PREORDER SEQUENCE WITH LEAF NODES INFO 
// Write an efficient algorithm to construct a full binary tree from a sequence of keys representing 
// preorder traversal and a boolean array named isLeaf that determines if the value at the corresponding index in the 
// preorder sequence is a leaf node or an internal node. (1 represents a leaf node, 0 represents an internal node)
// A full binary tree is a tree in which every node has either 0 or 2 children.
// Input: Preorder traversal : { 1, 2, 4, 5, 3, 6, 8, 9, 7 }
//        isLeaf array      : { 0, 0, 1, 1, 0, 0, 1, 1, 1 }

TreeNode *construct(vector<int> const &preorder, vector<bool> const &isLeaf, int& idx){
    TreeNode* root = new TreeNode(preorder[idx]);
    if(isLeaf[idx]) return root;
    idx++;
    root->left = construct(preorder, isLeaf, idx);
    idx++;
    root->right = construct(preorder, isLeaf, idx);
    return root;
}

TreeNode* constructTree(vector<int> const &preorder, vector<bool> const &isLeaf)
{
    int idx = 0; 
    return construct(preorder, isLeaf, idx);
}

//CONSTRUCT A BINARY TREE FROM INORDER AND LEVEL ORDER SEQUENCE
// Input: Inorder Traversal     : { 4, 2, 5, 1, 6, 3, 7 }
//        Level order traversal : { 1, 2, 3, 4, 5, 6, 7 }

