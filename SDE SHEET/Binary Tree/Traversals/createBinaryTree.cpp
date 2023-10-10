// https://www.codingninjas.com/studio/problems/create-binary-tree_8360671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* solve (int i, vector<int> &arr, int n) {
    Node* root = NULL;
    
    if (i < n) {
        root = new Node(arr[i]);
        root->left = solve(2*i+1, arr, n);
        root->right = solve(2*i+2, arr, n);
    }
    return root;
}
Node* createTree(vector<int>&arr){
    // Write your code here.
    int n = arr.size();
    return solve(0, arr, n);
}