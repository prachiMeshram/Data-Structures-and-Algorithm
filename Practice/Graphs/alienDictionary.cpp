// https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

#include<bits/stdc++.h>
using namespace std;


class Solution
{
private:
    vector<int> topoSort(int V, vector<int> adj[])
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

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);

        string ans = "";

        for (auto it : topo)
        {
            ans += char(it + 'a');
        }

        return ans;
    }
};