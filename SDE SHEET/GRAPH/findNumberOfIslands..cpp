// https://www.codingninjas.com/studio/problems/630512?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// USING DFS
void dfs (int r, int c, vector<vector<int>> &vis, int** arr) {
   int n = vis.size();
   int m = vis[0].size();
   vis[r][c] = -1;

   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         int nr = r+i;
         int nc = c+j;
         if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (vis[nr][nc]==1) {
               dfs(nr, nc, vis, arr);
            } 
         } 
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n, vector<int> (m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         vis[i][j] = arr[i][j];
      }
   }

   int ans = 0;


   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (vis[i][j] == 1) {
            dfs(i, j, vis, arr);
            ans++;
         } 
      }
   }

   return ans;
}


// USING BFS
void bfs (int r, int c, vector<vector<int>> &vis, int** arr) {
   int n = vis.size();
   int m = vis[0].size();
   vis[r][c] = -1;

   queue<pair<int, int>> q;
   q.push({r, c});

   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int i = -1; i <= 1; i++) {
         for (int j = -1; j <= 1; j++) {
            int nr = x+i;
            int nc = y+j;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
               if (vis[nr][nc]==1) {
                  vis[nr][nc] = -1;
                  q.push({nr, nc});
               } 
            } 
         }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n, vector<int> (m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         vis[i][j] = arr[i][j];
      }
   }

   int ans = 0;


   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (vis[i][j] == 1) {
            bfs(i, j, vis, arr);
            ans++;
         } 
      }
   }

   return ans;
}
