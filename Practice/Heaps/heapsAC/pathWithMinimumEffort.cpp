https://www.codingninjas.com/studio/problems/path-with-minimum-effort_1380958?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
using namespace std;

int minimumTimeTakingPath(vector<vector<int>>& heights){
	// Write your code here
	int n = heights.size();
	int m = heights[0].size();

	vector<vector<int>> d(n, vector<int> (m, INT_MAX));

	priority_queue<pair<int, pair<int, int>>,
						vector<pair<int, pair<int, int>>>, 
						greater<pair<int, pair<int, int>>>> q;

	d[0][0] = 0;
	q.push({0, {0, 0}});

	int dx[4] = {-1, 0, 1, 0}; 
	int dy[4] = {0, 1, 0, -1}; 

	while (!q.empty()) {
		auto it = q.top();
		q.pop();
		int dist = it.first;
		int x = it.second.first;
		int y = it.second.second;

		if (x == n-1 && y == m-1) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				
				int newEfforts = max(abs(heights[x][y] - heights[nx][ny]), dist);

				if (newEfforts < d[nx][ny]) {
					d[nx][ny] = newEfforts;
					q.push({newEfforts, {nx, ny}});
				}
			}
		}
	}
} 