#include<bits/stdc++.h>
using namespace std;

class Row {
    public:

    int soilders;
    int ind;

    Row(int s, int i): soilders(s), ind(i) {};
};

bool myComparision (Row &r1, Row &r2) {
    if (r1.soilders == r2.soilders) {
        return r1.ind > r2.ind;
    }
    return r1.soilders > r2.soilders;
}

int main () {
    
    vector<vector<int>> A = {
                            {1, 0, 0, 0},
                            {1, 1, 1, 1},
                            {1, 0, 0, 0}, 
                            {1, 0, 0, 0}
                            };
    int k = 2;
    int m = 4;
    int n = 4;

    priority_queue<Row, vector<Row>, decltype(&myComparision)> pq(&myComparision);

    for (int i = 0; i < m; i++) {
        int sol = 0;
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                sol++;
            }
        }
        pq.push(Row(sol, i));
    }
    
    for (int i = 0; i < k; i++) {
        cout << "R" << pq.top().ind << endl;
        pq.pop();
    }

    return 0;
}