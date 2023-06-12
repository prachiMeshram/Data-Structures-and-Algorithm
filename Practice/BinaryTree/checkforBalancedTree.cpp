#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    private:
    int height(Node *root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right) + 1;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if (root == NULL) {
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = (abs(height(root->left)-height(root->right))) <=1;
        
        if (left && right && diff) {
            return true;
        }
        return false;
    }
};
// OPTIMISED SPACE & TIME COMPLEXITY 
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
        if (root == NULL) {
            pair<bool, int> p = make_pair(1, 0);
            return p;
        }
        
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if (left.first && right.first && diff) {
            ans.first = true;
        }
        else {
            ans.second = false;
        }
        
        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        pair<bool, int> res = isBalancedFast(root);
        
        return res.first;
    }
};