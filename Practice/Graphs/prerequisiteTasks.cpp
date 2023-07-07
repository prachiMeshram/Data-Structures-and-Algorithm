// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> adj[N];

        for (auto it : prerequisites)
        {
            adj[it.second].push_back(it.first);
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

        if (cnt == N)
        {
            return true;
        }

        return false;
    }
};