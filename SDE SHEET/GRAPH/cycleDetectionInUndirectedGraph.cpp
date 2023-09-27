// https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;

    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode: adj[node]) {
            if (!vis[adjNode]) {
                q.push({adjNode, node});
                vis[adjNode] = 1;
            }
            else if (adjNode != parent) {
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];

    for (auto it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int vis[n+1] = {0};

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis)) {
                return "Yes";
            }
        }
    }
    return "No";
}
