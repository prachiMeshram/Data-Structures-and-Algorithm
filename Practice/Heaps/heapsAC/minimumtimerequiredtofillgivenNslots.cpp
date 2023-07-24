#include<bits/stdc++.h>
using namespace std;


int main () {
    int N = 6; // slots
    int K = 2;
    vector<int> arr = {2, 6};

    int counter = 0;
    
    queue<int> q;

    vector<int> vis (N+1, 0);
    
    for (int i = 0; i < K; i++) {
        vis[arr[i]] = 1;
        q.push(arr[i]);
    }

    int size = q.size();

    while (!q.empty()) {
        
        int temp = 0;
        for (int i = 0;  i < size; i++) {
            int curr = q.front();
            q.pop();

            if (curr-1 >= 1 && vis[curr-1] == 0) {
                vis[curr-1] = 1;
                q.push(curr-1);
                temp++;
            }

            if (curr+1 <= N && vis[curr+1] == 0) {
                vis[curr+1] = 1;
                q.push(curr+1);
                temp++;
            }
        }
        size = temp;
        counter++;
    }

    cout << counter - 1 ;
    return 0;
}