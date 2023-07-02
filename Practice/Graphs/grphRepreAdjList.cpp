#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction) {
    adj[u].push_back(v);
    if (direction) {
      adj[v].push_back(u);
    }
  }

  void printGraph() {

    for (auto i : adj) {

      cout << i.first << "->";

      for (auto j : i.second) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
};



int main() {
  std::cout << "Hello World!\n";

  // 5, 6
  int n;
  cout << "Enter # of node :" << endl;
  cin >> n;

  int m;
  cout << "Enter # of edges :" << endl;
  cin >> m;

  Graph g;
//   1 2
// 1 3
// 2 4
// 3 4 
// 3 5 
// 4 5

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    g.addEdge(u, v, 0);
  }

  g.printGraph();
}