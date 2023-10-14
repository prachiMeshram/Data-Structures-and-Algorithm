// https://www.codingninjas.com/studio/problems/insert-into-a-binary-search-tree_1279913?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
};

TreeNode<int> *insertionInBST(TreeNode<int> *root, int val)
{
    // Write your code here.
    if (root == NULL)
    {
        TreeNode<int> *temp = new TreeNode<int>(val);
        return temp;
    }

    TreeNode<int> *curr = root;

    while (true)
    {
        if (curr->val <= val)
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = new TreeNode<int>(val);
                break;
            }
        }
        else
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = new TreeNode<int>(val);
                break;
            }
        }
    }
    return root;
}