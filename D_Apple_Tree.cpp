#include<bits/stdc++.h>


using namespace std;


const long long int N = 1e6+2;
const long long int MOD = 1e9+7;


#define F	first
#define S	second
#define pb	push_back
#define POB	pop_back
#define MP	make_pair
#define ump	unordered_map
#define int	long long int
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pi;

bool checkLeaf(int node, vector<bool> &vis, vector<int> &nways, vector<vector<int>> &adj) {
    for (auto adjNode: adj[node]) {
        if (!vis[adjNode]) {
            return false;
        }
    }
    return true;
}

void dfs (int src, vector<bool> &vis, vector<int> &nways, vector<vector<int>> &adj) {
    vis[src] = true;
    
    if (checkLeaf(src, vis, nways, adj) ){  
        nways[src] = 1;
        return;
    }

    for (auto adjNode : adj[src]) {
        if (!vis[adjNode]) {
            dfs(adjNode, vis, nways, adj);
            nways[src] += nways[adjNode];
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<vector<int>> edges(n-1, vector<int> (2));

        for (int i = 0; i < n - 1; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        
        int q;
        cin >> q;
        
        vector<vector<int>> assump(q, vector<int> (2));
        for (int i = 0; i < q; i++) {
            cin >> assump[i][0] >> assump[i][1];
        }

        vector<vector<int>> adj(n+1);

        for (int i = 0; i < n-1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> nways(n+1, 0);
        vector<bool> vis(n+1, 0);

        dfs (1, vis, nways, adj);

        for (auto ass: assump) {
            cout << nways[ass[0]]*nways[ass[1]] << endl;
        }
    }

    return 0;
}