#include<bits/stdc++.h>
using namespace std;

bool sortCol (vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[2];
}


int main () {
    vector<vector<int>> pairs {
        {5, 24},
        {39, 60},
        {5, 28},
        {27, 40},
        {50, 90}
    };

    sort (pairs.begin(), pairs.end(), sortCol);

    int chainLen = 1;
    int pairEnd = pairs[0][1]; // last selected pair end // chain end
    for (int i = 1; i < pairs.size(); i++) {
        if(pairs[i][0] > pairEnd) {
            chainLen++;
            pairEnd = pairs[i][1];
        }
    }

    cout << chainLen << " ";

    return 0;
}