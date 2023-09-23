// https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_763671?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.

    if (root == NULL)
        return 0;

    queue<TreeNode<int> *> q;
    q.push(root);
    int ans = q.size();
    while (!q.empty())
    {

        int s = q.size();
        while (s--)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        int size = q.size();
        ans = max(ans, size);
    }

    return ans;
}