// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    // Function to detect cycle in an undirected graph.
    bool detectDFS(int node, int parent, vector<int> adj[], int vis[])
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (vis[adjNode] == 0)
            {
                if (detectDFS(adjNode, node, adj, vis) == true)
                {
                    return true;
                }
            }
            else if (adjNode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectDFS(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
