// https://www.codingninjas.com/studio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    vector<int> inO;
    vector<int> preO;
    vector<int> postO;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        TreeNode *node = it.first;
        int val = it.second;

        if (val == 1)
        {
            preO.push_back(node->data);
            it.second++;
            st.push(it);

            if (node->left)
            {
                st.push({node->left, 1});
            }
        }
        else if (val == 2)
        {
            inO.push_back(node->data);
            it.second++;
            st.push(it);

            if (node->right)
            {
                st.push({node->right, 1});
            }
        }
        else
        {
            postO.push_back(node->data);
        }
    }

    ans.push_back(inO);
    ans.push_back(preO);
    ans.push_back(postO);

    return ans;
}