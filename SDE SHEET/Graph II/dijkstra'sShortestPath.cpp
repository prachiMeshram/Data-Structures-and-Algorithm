// https://www.codingninjas.com/studio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// USING SET
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    // USING SET
    
    set<pair<int, int>> st;
    vector<int> dist(vertices, INT_MAX);

    vector<pair<int, int>> adj[vertices];

    for (auto it: vec) {
        int src = it[0];
        int des = it[1];
        int wt = it[2];
        adj[src].push_back({des, wt});
        adj[des].push_back({src, wt});
    }
    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty()) {
        auto it = *st.begin();
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for (auto it: adj[node]) {
            int edgewt = it.second;
            int adjNode = it.first;
            
            if(d + edgewt < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = d + edgewt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
} 

// USING PRIORITY QUQUE

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<pair<int, int>> adj[vertices];
    for (auto it: vec) {
        int src = it[0];
        int des = it[1];
        int wt = it[2];
        adj[src].push_back({des, wt});
        adj[des].push_back({src, wt});
    }

    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});


    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it: adj[node]) {
            int edgeWt = it.second;
            int adjNode = it.first;

            if (d + edgeWt < dist[adjNode]) {
                dist[adjNode] = d + edgeWt;
                pq.push({d + edgeWt, adjNode});
            }
        }
    }

    return dist;
}
