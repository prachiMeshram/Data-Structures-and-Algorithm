// https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_920552?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

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

int solve(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left = solve(root->left, ans);
    int right = solve(root->right, ans);
    ans = max(ans, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    if (root == NULL)
        return 0;
    int ans = 0;
    solve(root, ans);
    return ans;
}
