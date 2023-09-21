// https://www.codingninjas.com/studio/problems/postorder-traversal_3839614?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

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

//  Using two stacks
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    stack<TreeNode*> s1;
    stack<int> s2;
    
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* curr = s1.top();
        s1.pop();
        s2.push(curr->data);
        if (curr->left) {
            s1.push(curr->left);
        }
        if (curr->right) {
            s1.push(curr->right);
        }
    }
    
    while (!s2.empty()) {
        ans.push_back(s2.top());
        s2.pop();
    }
    return ans;
}