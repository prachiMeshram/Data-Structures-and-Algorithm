// https://www.codingninjas.com/studio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


#include<bits/stdc++.h>
using namespace std;

// USING TOPOSORT (KAHN'S ALGO)
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for (auto it: edges) {
    adj[it.first].push_back(it.second);
  }
  int inDeg[n+1] = {0};
  for (int i = 1; i <= n; i++) {
    for (auto it: adj[i]) {
      inDeg[it]++;
    }
  }
  
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (inDeg[i] == 0) {
      q.push(i);
    }
  }

  int cnt = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;
    
    for (auto it: adj[node]) {
      inDeg[it]--;
      if (inDeg[it] == 0) {
        q.push(it);
      }
    }
  }

  if (cnt == n) {
    return false;
  }
  return true;
}

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