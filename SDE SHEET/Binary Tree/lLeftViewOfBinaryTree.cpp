// https://www.codingninjas.com/studio/problems/920519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;


    // Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };


void recur(TreeNode<int> *node, int lvl, vector<int> &ans) {
    if (node == NULL) {
        return;
    }

    if (lvl == ans.size()) {
        ans.push_back(node->data);
    }
    recur(node->left, lvl+1, ans);
    recur(node->right, lvl+1, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    TreeNode<int>* curr = root;
    recur(curr, 0, ans);
    return ans;
}