// https://www.codingninjas.com/studio/problems/kth-smallest-node-in-bst_920441?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=2

#include<bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(T x) : data(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, in);
    in.push_back(root->data);
    inorderTraversal(root->right, in);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    //  Write the code here.
    vector<int> in;
    inorderTraversal(root, in);
    return in[k - 1];
}