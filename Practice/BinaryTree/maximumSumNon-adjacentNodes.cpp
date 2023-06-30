// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include <bits/stdc++.h> 
using namespace std;

// Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};


class Solution{
  private:
  pair<int, int> solve (Node *root) {
      if (root == NULL) {
          pair<int, int> p = make_pair(0, 0);
          return p;
      }
      
      pair<int, int> left = solve (root->left);
      pair<int, int> right = solve (root->right);
      
      pair<int, int> res;
      
      res.first = root->data + left.second + right.second;
      res.second = max(left.first, left.second) + max(right.first, right.second);
      
      return res;
      
  }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};