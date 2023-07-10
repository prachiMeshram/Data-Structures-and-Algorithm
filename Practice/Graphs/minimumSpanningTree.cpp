// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum = 0;
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // {wt, node}
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node])
            {
                continue;
            }

            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgWt = it[1];

                if (vis[adjNode] == 0)
                {
                    pq.push({edgWt, adjNode});
                }
            }
        }
        return sum;
    }
};