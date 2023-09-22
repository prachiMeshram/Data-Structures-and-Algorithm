// https://www.codingninjas.com/studio/problems/top-view-of-binary-tree_799401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

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

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mpp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int line = it.second;
        if (mpp.find(line) == mpp.end())
        {
            mpp[line] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
