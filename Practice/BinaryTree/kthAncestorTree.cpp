// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include <bits/stdc++.h> 
using namespace std;

// Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};

Node* solve (Node *root, int &k, int node) {
    
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == node) {
        return root;
    }

    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);

    if (left == NULL && right == NULL ) {
        return NULL;
    }
    
    if (left != NULL) {
        k--;
        if (k <=0) {
            k = INT_MAX;
            return root;
        }
        else {
            return left;
        }
    }
    if (right != NULL) {
        k--;
        if (k==0) {
            k = INT_MAX;
            return root;
        }
        else {
            return right;
        }
    }
    
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve (root, k, node);
    if (ans == NULL || ans->data == node) {
        return -1;
    }
    
    return ans->data;
}