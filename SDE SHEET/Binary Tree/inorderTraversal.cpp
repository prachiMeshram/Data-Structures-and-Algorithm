// https://www.codingninjas.com/studio/problems/inorder-traversal_3839605?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;


    // Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// MORRIS TRAVERSAL
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    TreeNode* curr = root;
    
    while (curr != NULL) {
        if (curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

// ITERATIVE TRAVERSAL

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode *curr = root;
    
    while (true) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            if (st.empty()) break;
            curr = st.top();
            ans.push_back(curr->data);
            st.pop();
            curr = curr->right;
        }
    }

    return ans;
}

// RECURSIVE APPROACH

void iotraversal(TreeNode *root, vector<int> &ans) {
    if (root == NULL ) {
        return;
    }
    iotraversal( root->left, ans);
    ans.push_back(root->data);
    iotraversal( root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    iotraversal(root, ans);
    return ans;
}