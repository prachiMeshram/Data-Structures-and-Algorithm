// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

#include <bits/stdc++.h> 
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges) {
            int src = it[0];
            int des = it[1];
            int wt = it[2];
            adj[src].push_back({des, wt});
            adj[des].push_back({src, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto it: adj[node]) {
                int adjNode = it.first;
                int edgewt = it.second;
                
                if (dis+edgewt < dist[adjNode]) {
                    dist[adjNode] = dis+edgewt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if (dist[n] == INT_MAX) return {-1};
        
        int node = n;
        vector<int> ans;
        while (parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};