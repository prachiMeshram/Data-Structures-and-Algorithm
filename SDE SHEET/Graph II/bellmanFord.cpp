// https://www.codingninjas.com/studio/problems/2041977?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;

    for (int i = 0; i < n-1; i++) {
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u]+wt < dist[v]) {
                dist[v] = dist[u]+wt;
            }
        }
    }
    // nth relaxing to check negative cycle
    for (auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u]+wt < dist[v]) {
            return {-1};
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        ans.push_back(dist[i]);
    }
    return dist;
}