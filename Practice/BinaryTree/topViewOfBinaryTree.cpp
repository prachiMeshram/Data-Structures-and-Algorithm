// https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> mpp;
    queue<pair<int, TreeNode *>> q;

    q.push({0, root});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.second;
        int x = p.first;

        if (mpp.find(x) == mpp.end())
        {
            mpp[x] = node->val;
        }

        if (node->left)
        {
            q.push({x - 1, node->left});
        }

        if (node->right)
        {
            q.push({x + 1, node->right});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}