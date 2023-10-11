// https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}
void addLBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addleafNode(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addleafNode(root->left, res);
    if (root->right)
        addleafNode(root->right, res);
}
void addRBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;

    stack<int> st;

    while (curr)
    {
        if (!isLeaf(curr))
            st.push(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        res.push_back(tp);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (root == NULL)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLBoundary(root, res);
    addleafNode(root, res);
    addRBoundary(root, res);

    return res;
}
