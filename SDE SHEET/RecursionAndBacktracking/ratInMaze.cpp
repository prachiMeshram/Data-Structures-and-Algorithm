// https://www.codingninjas.com/studio/problems/rat-in-a-maze-_8842357?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

void getPath(int row, int col, vector<string> &res, string s, vector<vector<int>> &mat, vector<vector<int>> &vis) {
    int n = mat.size();

    if (row == n-1 && col == n-1) {
        res.push_back(s);
        return;
    }

    // up
    if (row-1 >= 0 && vis[row-1][col] == 0 && mat[row-1][col] == 1) {
        vis[row][col] = 1;
        getPath(row-1, col, res, s+'U', mat, vis);
        vis[row][col] = 0;
    }
    // right
    if (col+1 < n && vis[row][col+1] == 0 && mat[row][col+1] == 1) {
        vis[row][col] = 1;
        getPath(row, col+1, res, s+'R', mat, vis);
        vis[row][col] = 0;
    }
    // down
    if (row+1 < n && vis[row+1][col] == 0 && mat[row+1][col] == 1) {
        vis[row][col] = 1;
        getPath(row+1, col, res, s+'D', mat, vis);
        vis[row][col] = 0;
    }
    // left
    if (col-1 >= 0 && vis[row][col-1] == 0 && mat[row][col-1] == 1) {
        vis[row][col] = 1;
        getPath(row, col-1, res, s+'L', mat, vis);
        vis[row][col] = 0;
    }

}
vector<string> ratMaze(vector<vector<int>> &mat) {
    // Write your code here.
    int n = mat.size();
    
    vector<string> res;
    string s = "";
    vector<vector<int>> vis(n, vector<int> (n, 0));
    getPath(0, 0, res, s, mat, vis);
    return res;
}