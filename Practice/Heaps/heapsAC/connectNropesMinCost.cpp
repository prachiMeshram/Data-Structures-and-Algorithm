#include<bits/stdc++.h>
using namespace std;

int main () {
    
    int arr[5] = {2, 3, 3, 4, 6};

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < 5; i++) {
        pq.push(arr[i]);
    }

    int cost = 0;

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int sec = pq.top();
        pq.pop();

        cost += first + sec;

        pq.push(first + sec);  
    }

    cout << cost << " ";

    return 0;
}