// https://www.codingninjas.com/studio/problems/topological-sort_982938?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// DFS
void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  // Write your code here
    vector<int> topo;

    vector<int> adj[v];

    for (auto it : edges) {
        int src = it[0];
        int des = it[1];

        adj[src].push_back(des);
    }
    int vis[v] = {0};
    stack<int> st;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

// BFS
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  // Write your code here
  vector<int> topo;

  vector<int> adj[v];

  for (auto it : edges) {
        int src = it[0];
        int des = it[1];

        adj[src].push_back(des);
    }
    int inDeg[v] = {0};

    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            inDeg[it]++;
        }
    }
    queue<int> q;

    for (int i = 0; i < v; i++ ) {
        if (inDeg[i]==0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it: adj[node]) {
            inDeg[it]--;
            if (inDeg[it] == 0) {
                q.push(it);
            }
        }
    }

    return topo;

}