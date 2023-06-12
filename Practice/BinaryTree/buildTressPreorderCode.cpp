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

Node* BinaryTree(Node* root) {
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for  2inserting in left of " << data << endl;
    root -> left = BinaryTree (root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = BinaryTree (root-> right);

    return root;
}

int main () {
    Node* root = NULL;

    // creating a tree;
    root = BinaryTree(root);

    return 0;
}