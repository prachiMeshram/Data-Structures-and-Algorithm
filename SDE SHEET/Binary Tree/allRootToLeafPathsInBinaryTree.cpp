// https://www.codingninjas.com/studio/problems/all-root-to-leaf-paths-in-binary-tree._983599?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:
template <typename T = int>
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root, string s, vector<string> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        s += to_string(root->data);
        ans.push_back(s);
        return;
    }
    s += to_string(root->data) + " ";
    solve(root->left, s, ans);
    solve(root->right, s, ans);
}
vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<string> ans;
    solve(root, "", ans);
    return ans;
}