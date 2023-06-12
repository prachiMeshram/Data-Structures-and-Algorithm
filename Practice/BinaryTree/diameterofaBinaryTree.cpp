#include<iostream>
#include<bits/stdc++.h>


using namespace std;


const long long int N = 1e6+2;
const long long int MOD = 1e9+7;


#define F	first
#define S	second
#define pb	push_back
#define POB	pop_back
#define MP	make_pair
#define ump	unordered_map
#define int	long long int
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pi;

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

pair<int, int> diameterFast(Node* root) {
    if (root == NULL) {
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left); 
    pair<int, int> right = diameterFast(root->right); 

    int d1 = left.first;
    int d2 = right.first;
    int d3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(d1, max(d2, d3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter (Node* root) {
    pair<int, int> ans = diameterFast(root);
    return ans.first;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}