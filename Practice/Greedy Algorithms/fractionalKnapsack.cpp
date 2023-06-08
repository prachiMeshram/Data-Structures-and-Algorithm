#include<bits/stdc++.h>
using namespace std;

bool sortCol (vector<double> &v1, vector<double> &v2) {
    return v1[1] < v2[2];
}

int main () {
    vector<int> val = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;

    int n = val.size();
    vector<vector<double>> ratio(n, vector<double>(2, 0));

    for (int i = 0; i < n; i++) {
        ratio[i][0] = i;
        ratio[i][1] = val[i] / (double)weight[i];
    }

    sort(ratio.begin(), ratio.end(), sortCol);

    int maxVal = 0;
    int capacity = W;

    for (int i = 0; i < n; i++) {
        int ind = ratio[i][0];
        if (capacity >= weight[ind]) { // include full item
            capacity -= weight[ind];
            maxVal += val[ind];
        }
        else { // include fractional item
            maxVal +=  capacity*ratio[i][1];
            capacity = 0;
            break;
        }
    }

    cout << maxVal << " ";

    return 0;
}