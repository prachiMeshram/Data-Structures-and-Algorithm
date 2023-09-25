// https://www.codingninjas.com/studio/problems/check-identical-trees_799364?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=2

#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree Node class structure:

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // Write your code here.
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }

    if (root1->data == root2->data)
    {
        if (identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right))
        {
            return true;
        }
    }
    return false;
}