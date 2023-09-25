// https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_975497?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode<int> *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    if (left == -1)
        return -1;

    int right = height(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;
    return 1 + max(left, right);
}
bool isBalancedBT(TreeNode<int> *root)
{
    // Write your code here.
    if (height(root) != -1)
        return true;
    return false;
}