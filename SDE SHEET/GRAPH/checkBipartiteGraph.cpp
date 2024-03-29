// https://www.codingninjas.com/studio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// USING BFS
#include<bits/stdc++.h>

bool bfs(int n, int col[], vector<int> adj[]) {

	col[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto it: adj[node]) {
			if (col[it] == -1) {
				col[it] = !col[node];
				q.push(it);
			}
			else if (col[it] == col[node]) {
				return false;
			}
		}
	} 
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.

	int n = edges.size();
	int m = edges[0].size();
	
	// int v = max(n, m) + 1;
	vector<int> adj[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (edges[i][j]) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}	
		}
	}

	int col[n];
	for (int i = 0; i < n; i++) col[i] = -1;

	for (int i = 0; i < n; i++) {
		if (col[i] == -1) {
			if (bfs(i,col, adj) == false) return false;
		}
	}
	return true;
}

// USING DFS
bool dfs(int node, int col, int vis[], vector<int> adj[]) {
	vis[node] = col;

	for (auto it: adj[node]) {

		if (vis[it] == -1) {
			if (dfs(it, !col, vis, adj) == false) return false;
		}
		else if (col == vis[it]) {
			return false;
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.

	int n = edges.size();
	int m = edges[0].size();
	
	// int v = max(n, m) + 1;
	vector<int> adj[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (edges[i][j]) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}	
		}
	}

	int vis[n];
	for (int i = 0; i < n; i++) vis[i] = -1;

	for (int i = 0; i < n; i++) {
		if (vis[i] == -1) {
			if (dfs(i, 0, vis, adj) == false) return false;
		}
	}
	return true;
}