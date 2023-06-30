// https://www.codingninjas.com/studio/problems/convert-a-binary-tree-to-its-sum-tree_920395?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

    // Following is the Binary Tree node class:
        
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->data = val;
            left = NULL;
            right = NULL;
        }
    };

    int solve (TreeNode<int> *root) {
        if (root == NULL) {
            return 0;
        }

        
        int oldLeft = solve (root->left); 
        int oldRight = solve (root->right); 

        int curr = root->data;
        int newLeft = root->left==NULL ? 0 : root->left->data; 
        int newRight = root->right==NULL ? 0 : root->right->data; 
        
        root->data = oldLeft + newLeft + oldRight + newRight;
        return curr;
    }

TreeNode<int> *convertToSumTree(TreeNode<int> *root) {
    // Write your code here.
    // base case
    if (root == NULL) {
        return NULL;
    }

    int temp = solve (root);
    
    return root;
}