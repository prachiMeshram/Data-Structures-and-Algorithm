#include<bits/stdc++.h>
using namespace std;

int main () {

    vector<int> coins {1, 2, 5, 10, 20, 50, 100, 500, 2000};

    int n = coins.size();

    sort(coins.begin(), coins.end());

    int count = 0;
    int amount = 590;
    vector<int> ans;

    for (int i = n-1; i >=0; i--) {
        if (coins[i] <= amount) {
            while (coins[i] <= amount) {
                count++;
                ans.push_back(coins[i]);
                amount -= coins[i];
            }
        }
    }

    cout << "coins count: " << count << endl;
    cout << "coins: " << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}