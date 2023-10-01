// https://www.codingninjas.com/studio/problems/2041979?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;


int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> matrix(n+1, vector<int> (n+1, 1e9));
    for (int i = 0; i <= n; i++) {
        matrix[i][i] = 0;
    }
    for (auto it: edges) {
        int sr = it[0];
        int de = it[1];
        int wt = it[2];
        matrix[sr][de] = wt;
    }
    

    
    for(int via = 1; via <= n; via++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i][via] != 1e9 && matrix[via][j] != 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via]+matrix[via][j]);
                }
            }
        }
    }
    
    // to detect negative cycle
    // for (int i = 1; i <= n; i++) {
    //     if (matrix[i][i] < 0) {
    //         return -1;
    //     }
    // }

    return matrix[src][dest];
}