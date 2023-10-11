// https://codingninjas.com/studio/problems/maximum-width-in-binary-tree_763671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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
    if (!root)
        return 0;
    int ans = 0;
    queue<TreeNode<int> *> q;

    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);

        while (size > 0)
        {
            auto it = q.front();
            q.pop();

            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
            size--;
        }
    }

    return ans;
}