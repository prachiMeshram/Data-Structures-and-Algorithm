// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include<iostream>
using namespace std;
#include <vector>

 
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
void solve(TreeNode* root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    ans.push_back(root->val);
    solve(root->left, ans);
    solve(root->right, ans);
}

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};