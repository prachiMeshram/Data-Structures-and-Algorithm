// https://www.codingninjas.com/studio/problems/left-view-of-binary-tree_625707?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;

    if (res.size() == level)
        res.push_back(root->data);
    solve(root->left, level + 1, res);
    solve(root->right, level + 1, res);
}
vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    // Write your code here

    vector<int> res;
    solve(root, 0, res);
    return res;
}