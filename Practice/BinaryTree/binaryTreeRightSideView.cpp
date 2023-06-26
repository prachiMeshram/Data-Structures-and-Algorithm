// https://leetcode.com/problems/binary-tree-right-side-view/description/

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

class Solution {
private: 
    void sol (TreeNode* root, int level, vector<int> &res) {
        if (root == NULL) {
            return;
        }

        if (res.size() == level) {
            res.push_back(root->val);
        }

        sol(root->right, level+1 ,res);
        sol(root->left, level+1 ,res);

        return;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; 

        if (root == NULL) {
            return res;
        }

        sol(root, 0 ,res);

        return  res;
    }
};