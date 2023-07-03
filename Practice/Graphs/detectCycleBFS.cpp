// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for (auto adjNode : adj[node])
            {

                if (!vis[adjNode])
                {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if (parent != adjNode)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};

        for (int i = 1; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};