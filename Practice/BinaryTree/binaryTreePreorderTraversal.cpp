// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include<iostream>
using namespace std;
#include <vector>
#include <stack>

 
//   Definition for a binary tree node.
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
// USING RECURSION
// void solve(TreeNode* root, vector<int> &ans) {
//     if (root == NULL) {
//         return;
//     }
//     ans.push_back(root->val);
//     solve(root->left, ans);
//     solve(root->right, ans);
// }

// USING ITERATION
void solve (TreeNode* root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();

        ans.push_back(curr->val);

        // Push the right child first so that it gets processed after the left child
        if (curr->right) {
            s.push(curr->right);
        }
        if (curr -> left) {
            s.push(curr->left);
        }
    }
}

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};