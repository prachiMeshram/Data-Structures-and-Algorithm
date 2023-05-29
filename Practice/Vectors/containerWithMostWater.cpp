
#include<bits/stdc++.h>
using namespace std;

int maxWater(vector<int> &vec) {
    int maxi = INT_MIN;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i+1; j < vec.size(); j++) {
            int height = min(vec[i], vec[j]);
            int width = j-i;
            int water = height*width;
            maxi = max(maxi, water);
        }
    }

    return maxi;
}

int main () {
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxWater(vec) << " ";

    return 0;
}