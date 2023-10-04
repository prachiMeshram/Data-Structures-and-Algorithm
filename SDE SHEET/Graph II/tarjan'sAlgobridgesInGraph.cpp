// https://www.codingninjas.com/studio/problems/bridges-in-a-graph_893026?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

// Bridges in Graph – Using Tarjan’s Algorithm of time in and low time

#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs (int node, int parent, int tin[], int low[], vector<int> &vis, vector<int> adj[], vector<vector<int>> &bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    
    for (auto it: adj[node]) {
        if (it == parent) continue;
        if (vis[it] == 0) {
            dfs(it, node, tin, low, vis, adj, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node]) {
                bridges.push_back({it, node});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }

}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<int> adj[v+1];
    for (auto it: edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(v+1, 0);
    int tin[v+1];
    int low[v+1];
    vector<vector<int>> bridges;

    dfs(0, -1, tin, low, vis, adj, bridges);

    return bridges;
}