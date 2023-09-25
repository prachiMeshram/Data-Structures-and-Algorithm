// https://www.codingninjas.com/studio/problems/lca-of-binary-tree_920541?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    if (root == NULL)
        return -1;
    if (root->data == x || root->data == y)
    {
        return root->data;
    }

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if (left == -1)
    {
        return right;
    }
    else if (right == -1)
    {
        return left;
    }
    return root->data;
}