// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &temp, int vis[], vector<int> adj[]) {
    vis[node] = 1;
    temp.push_back(node);

    for (auto it: adj[node]) {
        if (vis[it] == 0) {
            dfs(it, temp, vis, adj);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    vector<int> adj[V];
    for (auto it: edges) {
        int src = it[0];
        int des = it[1];
        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    int vis[V];
    for (int i = 0; i < V; i++) vis[i] = 0;

    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) {
            vector<int> temp;
            dfs(i, temp, vis, adj);
            ans.push_back(temp);
        }
    }
    return ans;
}