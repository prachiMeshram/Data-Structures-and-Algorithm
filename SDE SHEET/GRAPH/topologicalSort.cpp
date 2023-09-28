// https://www.codingninjas.com/studio/problems/topological-sort_982938?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// DFS
bool dfsCheck(int node, int vis[], int pathVis[], vector<int> adj[]) {
  vis[node] = 1;
  pathVis[node] = 1;
  
  for (auto it: adj[node]) {
    if (!vis[it]) {
      if (dfsCheck(it, vis, pathVis, adj)) return true;
    }
    else if (pathVis[it]) {
      return true;;
    }
  }

  pathVis[node] = 0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for (auto it: edges) {
    adj[it.first].push_back(it.second);
  }
  int vis[n+1] = {0};
  int pathVis[n+1] = {0};
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfsCheck(i, vis, pathVis, adj))return true;
    }
  }
  return false;
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