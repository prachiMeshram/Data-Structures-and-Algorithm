// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

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
        left = NULL;
        right = NULL;
    }
};


void solve (Node *root, int sum, int len, int &maxLen, int &maxSum) {
        if (root == NULL) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        sum += root->data;
        
        solve(root->left, sum, len+1, maxLen, maxSum);
        solve(root->right, sum, len+1, maxLen, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = 0;
        
        solve (root, sum, len, maxLen, maxSum);
        
        return maxSum;
    }