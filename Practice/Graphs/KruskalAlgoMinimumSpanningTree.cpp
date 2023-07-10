// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
    
    public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1, 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            return;
        }
        
        if (size[ulp_v] < size[ulp_u]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    
    int findUPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionRank (int u, int v) {
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);
        
        if (ulp_v == ulp_u) {
            return;
        }
        
        if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int,int>>> edges;
        
        for (int i = 0; i < V; i++) {
            for (auto it: adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        DisjointSet ds(V);
        
        sort(edges.begin(), edges.end());
        
        int mst = 0;
        
        for (auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mst += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mst;
    }
};
