// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public :

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        
        vector<int> vis(V, 0);
        vis[0] = 1;
        
        queue<int> q;
        
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto i: adj[node]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
