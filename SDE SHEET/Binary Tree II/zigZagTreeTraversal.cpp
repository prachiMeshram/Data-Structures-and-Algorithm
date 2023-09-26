// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include <bits/stdc++.h>
using namespace std;

// Structure of the node of the binary tree is as
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<Node *> q;
        q.push(root);
        bool flag = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                int j = (flag) ? i : (size - 1 - i);
                v[j] = node->data;

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            flag = !flag;
            for (auto it : v)
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};