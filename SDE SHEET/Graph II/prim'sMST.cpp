// https://www.codingninjas.com/studio/problems/1095633?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int, int>> adj[n+1];
    for (auto it: g) {
        int src = it.first.first;
        int des = it.first.second;
        int wt = it.second;
        adj[src].push_back({des, wt});
        adj[des].push_back({src, wt});
    }
    vector<int> vis(n+1, 0);
    vector<pair<pair<int, int>, int>> mst;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    pq.push({0, {1, -1}});

    while (!pq.empty()) {
        auto it = pq.top();
        int wt = it.first;
        int currNode = it.second.first;
        int currParent = it.second.second;
        pq.pop();

        if (vis[currNode]) continue;
        vis[currNode] = 1;
        mst.push_back({{currNode, currParent}, wt});

        for (auto it: adj[currNode]) {
            int adjnode = it.first;
            int edgewt = it.second;
            if (!vis[adjnode]) {
                pq.push({edgewt, {adjnode, currNode}});
            }
        }
    }
    mst.erase(mst.begin(), mst.begin()+1);
    return mst;
}
