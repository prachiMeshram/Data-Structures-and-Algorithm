// https://www.codingninjas.com/studio/problems/symmetric-tree_981177?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure:

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

bool solve(TreeNode<int> *l, TreeNode<int> *r)
{
    if (l == NULL || r == NULL)
        return l == r;
    if (l->data != r->data)
        return false;

    solve(l->left, r->right);
    solve(l->right, r->left);
}
bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return true;
    return solve(root->left, root->right);
}