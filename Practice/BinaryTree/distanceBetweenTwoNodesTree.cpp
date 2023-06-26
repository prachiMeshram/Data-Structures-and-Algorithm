// https://www.codingninjas.com/studio/problems/distance-between-two-nodes-of-a-tree_800303?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

bool findNode(TreeNode<int>* root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->val == target) {
        return true;
    }
    return findNode(root->left, target) || findNode(root->right, target);
}

TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, int p, int q) {
    if (root == NULL || root->val == p || root->val == q) {
        return root;
    }

    TreeNode<int>* leftLca = lowestCommonAncestor(root->left, p, q);
    TreeNode<int>* rightLca = lowestCommonAncestor(root->right, p, q);

    if (leftLca != NULL && rightLca != NULL) {
        return root;
    }
    else if (leftLca != NULL) {
        return leftLca;
    }
    else {
        return rightLca;
    }
}

int distanceFromRoot(TreeNode<int>* root, int target) {
    if (root == NULL) {
        return -1;
    }
    if (root->val == target) {
        return 0;
    }
    int leftDist = distanceFromRoot(root->left, target);
    int rightDist = distanceFromRoot(root->right, target);
    if (leftDist == -1 && rightDist == -1) {
        return -1;
    }
    else if (leftDist == -1) {
        return rightDist+1;
    }
    else {
        return leftDist+1;
    }
}

int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    // Write your code here.
    if (root == NULL) {
        return -1;
    }
    if (!findNode(root, node1) || !findNode(root, node2)) {
        return -1; // Either node1 or node2 is not present in the tree
    }

    TreeNode<int>* lca = lowestCommonAncestor(root, node1, node2);

    int dist1 = distanceFromRoot(lca, node1);
    int dist2 = distanceFromRoot(lca, node2);

    return dist1 + dist2;
}