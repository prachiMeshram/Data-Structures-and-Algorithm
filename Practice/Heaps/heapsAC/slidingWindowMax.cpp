#include<bits/stdc++.h>
using namespace std;

class info {
    public:

    int val;
    int ind;

    info(int v, int i): val(v), ind(i) {};
};

bool myComparision (info &i1, info &i2) {
    return i1.val < i2.val;
}

int main () {
    
    vector<int> v = {1, 3, -1, -1, 5, 3, 6, 7};
    int k = 3;
    int n = v.size();

    priority_queue<info, vector<info>, decltype(&myComparision)> pq(&myComparision);

    vector<int> res;

    for(int i = 0; i < k; i++) {
        pq.push(info(v[i], i));
    }

    res.push_back(pq.top().val);

    for (int i = k; i < n; i++) {
        while (!pq.empty() && pq.top().ind <= (i-k)) {
            pq.pop();
        }
        pq.push(info(v[i], i));
        res.push_back(pq.top().val);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}