// https://www.codingninjas.com/studio/problems/delete-node-in-bst_920381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

BinaryTreeNode<int> *findLastChild(BinaryTreeNode<int> *curr)
{
    {
        if (curr->right == NULL)
            return curr;

        return findLastChild(curr->right);
    }
}

BinaryTreeNode<int> *helper(BinaryTreeNode<int> *root)
{
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;

    BinaryTreeNode<int> *rightChild = root->right;
    BinaryTreeNode<int> *lastRight = findLastChild(root->left);
    lastRight->right = rightChild;

    return root->left;
}

BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return helper(root->left);

    BinaryTreeNode<int> *dummy = root;

    while (root)
    {
        if (key < root->data)
        {
            if (root->left != NULL && root->data == key)
            {
                root->left = helper(root->left);
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->data == key)
            {
                root->right = helper(root->right);
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}
