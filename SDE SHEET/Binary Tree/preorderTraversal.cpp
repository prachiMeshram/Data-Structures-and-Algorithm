// https://www.codingninjas.com/studio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 
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

// ITERATIVE APPROACH
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here. 
    
    vector<int> ans;
    if (root == NULL) return ans;
    TreeNode* curr = root;
    stack<TreeNode*> st;
    st.push(curr);

    while (!st.empty()) {
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        if (curr->right!=NULL) {
            st.push(curr->right);
        }
        if (curr->left!=NULL){
            st.push(curr->left);
        }
    }

    return ans;
}

// RECURSIVE APPRROACH
void preOTrav(TreeNode* root, vector<int> &ans) {
    if (root == NULL) return;

    ans.push_back(root->data);
    preOTrav(root->left, ans);
    preOTrav(root->right, ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here. 
    vector<int> ans;
    preOTrav(root, ans);
    return ans;
}