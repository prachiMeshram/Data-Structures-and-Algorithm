#include <bits/stdc++.h>
using namespace std;

int main () {

    vector<int> prices{7, 1, 5, 3, 6, 4};

    int maxProfit = 0;
    int miniBuyPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        miniBuyPrice = min(miniBuyPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i]-miniBuyPrice);

    }
    cout << maxProfit;
    return 0;
}