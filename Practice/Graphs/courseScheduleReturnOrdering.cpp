// https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        int N = n;
        
        vector<int> adj[N];

        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        int inDeg[N] = {0};

        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                inDeg[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                inDeg[it]--;
                if (inDeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (topo.size() == N)
        {
            return topo;
        }

        return {};
    }
}