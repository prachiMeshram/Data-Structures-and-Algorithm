#include<bits/stdc++.h>
using namespace std;


int main () {
    int N = 5; // slots
    int K = 5;
    vector<int> arr = {1, 2, 3, 4, 5};

    int counter = 0;
    
    queue<int> q;

    vector<int> vis (N+1, 0);
    
    for (int i = 0; i < K; i++) {
        vis[arr[i]] = 1;
        q.push(arr[i]);
    }
    
    while (!q.empty()) {

        for (int i = 0;  i < q.size(); i++) {
            int curr = q.front();
            q.pop();

            if (curr-1 >= 1 && vis[curr-1] == 0) {
                vis[curr-1] = 1;
                q.push(curr-1);
            }

            if (curr+1 <= N && vis[curr+1] == 0) {
                vis[curr+1] = 1;
                q.push(curr+1);
            }
        }
        
        counter++;
    }

    cout << counter - 1 ;
    return 0;
}