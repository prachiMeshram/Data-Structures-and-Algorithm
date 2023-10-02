// https://www.codingninjas.com/studio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
	vector<int> size, parent;
	
	public:

	DisjointSet (int n) {
		size.resize(n+1, 1);
		parent.resize(n+1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	int findUPar(int node) {
		if (node == parent[node]) return node;
		return parent[node] = findUPar(parent[node]);
	}

	void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);

		if (ulp_u == ulp_v) return;
		if (size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else {
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}
};

bool comp (vector<int> &x, vector<int> &y) {
	return x[2] < y[2];
}
int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.
	DisjointSet ds(n);
	int mst = 0;
	sort(edges.begin(), edges.end(), comp);

	for (auto it: edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];

		if (ds.findUPar(u) != ds.findUPar(v)) {
			mst += wt;
			ds.unionBySize(u, v);
		}
	}
	return mst;
}
