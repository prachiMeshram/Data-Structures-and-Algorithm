// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

// POSTORDER TRAVERSAL RECURSIVELY
// void solve(TreeNode* root, vector<int> &ans) {
//     if (root == NULL) {
//         return;
//     }

//     solve (root->left, ans);
//     solve (root->right, ans);
//     ans.push_back(root->val);
// }

// ITERATIVELY USING TWO STACKS
void solve(TreeNode* root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    
    st1.push(root);

    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left) {
            st1.push(root->left);
        }

        if (root->right) {
            st1.push(root->right);
        }
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
}

// ITERATION SINGLE STACKS
void solve(TreeNode* root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {

        if (curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            TreeNode* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);

                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else {
                curr = temp;
            }
        }
    }
}

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};