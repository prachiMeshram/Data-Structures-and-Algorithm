// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs2(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;

        for (auto it : adjT[node])
        {
            if (vis[it] == 0)
            {
                dfs2(it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] != 1)
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];

        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        int scc = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (vis[node] == 0)
            {
                scc++;
                dfs2(node, vis, adjT);
            }
        }

        return scc;
    }
};