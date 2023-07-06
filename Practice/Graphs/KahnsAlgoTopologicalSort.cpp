// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int inDeg[V] = {0};
	    
	    for (int i = 0; i < V; i++) {
	        for (auto it: adj[i]) {
	            inDeg[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for (int i = 0; i < V; i++) {
	        if (inDeg[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    
	    while (!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it: adj[node]) {
	            inDeg[it]--;
	            if (inDeg[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    
	    return topo;
	}
};