// https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (vis[it] == 0)
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // Code here
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i])
            {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
    }
};