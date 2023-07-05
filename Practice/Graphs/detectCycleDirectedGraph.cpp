// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: 
  bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]) {
      vis[node] = 1;
      pathVis[node] = 1;
      
      for (auto it: adj[node]) {
          if (vis[it] == 0) {
              if (dfs(it, adj, vis, pathVis) == true) {
                  return true;
              }
          }
          else if (pathVis[it] == 1) {
              return true;
          }
      } 
      
      
      pathVis[node] = 0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis, pathVis) == true) {
                    return true;
                }
            } 
        }
        return false;
    }
};