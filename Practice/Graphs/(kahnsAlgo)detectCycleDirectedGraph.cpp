// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int inDeg[V] = {0};

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDeg[it]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node])
            {
                inDeg[it]--;
                if (inDeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (cnt == V)
        {
            return false;
        }

        return true;
    }
};