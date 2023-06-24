// https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0


#include <bits/stdc++.h> 
using namespace std;

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

bool getPath(TreeNode<int> *root, vector<TreeNode<int> *> &path, int P)
{
    if (root == NULL)
    {
        return false;
    }
    
    path.push_back(root);

    if (root->data == P)
    {
        return true;
    }

    if (getPath(root->left, path, P) || getPath(root->right, path, P))
    {
        return true;
    }

    path.pop_back();
    return false;
}

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    if (root == NULL || P == NULL || Q == NULL)
    {
        return NULL;
    }

    vector<TreeNode<int> *> pathP;
    vector<TreeNode<int> *> pathQ;

    bool p1 = getPath(root, pathP, P->data);
    bool q1 = getPath(root, pathQ, Q->data);

    if (!p1 || !q1)
    {
        return NULL;
    }

    int i = 0;
    for (; i < pathP.size() && i < pathQ.size(); i++)
    {
        if (pathP[i]->data != pathQ[i]->data)
        {
            break;
        }
    }

    return pathP[i - 1];
}
