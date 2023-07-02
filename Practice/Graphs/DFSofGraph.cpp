// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

#include <bits/stdc++.h>
using namespace std;

class solution
{
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);

        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;

        vector<int> vis(V, 0);

        // vis[0] = 1;

        dfs(0, adj, vis, ans);
        return ans;
    }
};