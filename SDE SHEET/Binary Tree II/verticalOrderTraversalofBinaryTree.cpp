// https://www.codingninjas.com/studio/problems/vertical-order-traversal_3622711?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int> *temp = p.first;

        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(temp->data);

        if (temp->left)
        {
            q.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {x + 1, y + 1}});
        }
    }

    for (auto it : nodes)
    {
        for (auto n : it.second)
        {
            res.insert(res.end(), n.second.begin(), n.second.end());
        }
    }
    return res;
}