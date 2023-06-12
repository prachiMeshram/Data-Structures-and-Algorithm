// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include<iostream>
using namespace std;
#include <vector>
#include <stack>


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



class Solution {
private:
// RECURSIVELY
// void solve(TreeNode* root, vector<int> &ans) {
//     if (root == NULL) {
//         return;
//     }

//     solve(root->left, ans);
//     ans.push_back(root->val);
//     solve(root->right, ans);

// }

// ITERATIVELY
void solve(TreeNode* root, vector<int> &ans) {
    stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr || !s.empty()) {

        // travel to left nodes of curr
        while (curr) {
            s.push(curr);
            curr = curr->left; 
        }

        curr = s.top();
        s.pop();
        ans.push_back(curr->val);

        //
        curr = curr->right;
    }
}

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};