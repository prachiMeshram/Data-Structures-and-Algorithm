// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    private:
    void traverseLeft(Node *root, vector<int> &ans) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return;
        }
        
        ans.push_back(root->data);
        
        if (root->left) {
            traverseLeft(root->left, ans);
        }
        else {
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node *root, vector<int> &ans) {
        if (root == NULL) {
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

    }
    
    void traverseRight(Node *root, vector<int> &ans) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return;
        }
        
        if (root->right) {
            traverseRight(root->right, ans);
        }
        else {
            traverseRight(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        ans.push_back(root->data);
        
        // print left (excluding root)
        traverseLeft(root->left, ans);
        
        
        // print leaf nodes
        // print left leaf nodes
        traverseLeaf(root->left, ans);
        // print right leaf nodes
        traverseLeaf(root->right, ans);
        
        // print right (excluding root)
        traverseRight(root->right, ans);
        
        return ans;
    }
};