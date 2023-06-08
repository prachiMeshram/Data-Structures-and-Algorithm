#include<bits/stdc++.h>
using namespace std;

int main () {

    int n = 4, m = 6;
    vector<int> verCost{2, 1, 3, 1, 4};
    vector<int> horCost{4, 1, 2};

    sort(verCost.begin(), verCost.end());
    sort(horCost.begin(), horCost.end());

    int h = horCost.size()-1;
    int v = verCost.size()-1;
    int vp = 1;
    int hp = 1;
    int totalCost = 0;

    while (h>=0 && v>=0) {
        if (verCost[v] > horCost[h]) {
            totalCost += hp*verCost[v];
            vp++;
            v--;
        }
        else {
            totalCost += vp*horCost[h];
            hp++;
            h--;
        }
    }

    while (v>=0) {
        totalCost += hp*verCost[v];
        vp++;
        v--;
    }
    
    while (h>=0) {
        totalCost += vp*horCost[h];
            hp++;
            h--;
    }

    cout << totalCost << " ";

    return 0;
}