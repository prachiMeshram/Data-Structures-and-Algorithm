// https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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

vector<int> bottomView(TreeNode<int> *root)
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
        auto curr = q.front();
        q.pop();
        TreeNode<int> *n = curr.first;
        int l = curr.second;
        mpp[l] = n->data;

        if (n->left != NULL)
        {
            q.push({n->left, l - 1});
        }
        if (n->right != NULL)
        {
            q.push({n->right, l + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
