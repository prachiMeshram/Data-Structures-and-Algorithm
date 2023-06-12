#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* left;
    Node* right;
    
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BinaryTreePreOrder(Node* root) {
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for  2inserting in left of " << data << endl;
    root -> left = BinaryTreePreOrder(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = BinaryTreePreOrder(root-> right);

    return root;
}

int main () {
    Node* root = NULL;

    // creating a tree;
    root = BinaryTreePreOrder(root);

    return 0;
}