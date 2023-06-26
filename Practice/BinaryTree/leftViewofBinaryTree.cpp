// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to return a list containing elements of left view of the binary tree.

void f(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }

    if (res.size() == level)
    {
        res.push_back(root->data);
    }

    f(root->left, level + 1, res);
    f(root->right, level + 1, res);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> res;

    if (root == NULL)
    {
        return res;
    }

    f(root, 0, res);

    return res;
}