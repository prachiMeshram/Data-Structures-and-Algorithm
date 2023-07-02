#include<bits/stdc++.h>
using namespace std;

// ADJECENCY MATRIX
int main () {

    // n: nodes/vertices
    // m: edges
    int n , m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    vector<vector<int>> adj (n+1, vector<int> (n+1, 0));

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1; // this statement will be removed in case of directed graph
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}