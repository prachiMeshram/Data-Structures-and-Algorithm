
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// int maxWater(vector<int> &vec) {
//     int maxi = INT_MIN;

//     for (int i = 0; i < vec.size(); i++) {
//         for (int j = i+1; j < vec.size(); j++) {
//             int height = min(vec[i], vec[j]);
//             int width = j-i;
//             int water = height*width;
//             maxi = max(maxi, water);
//         }
//     }

//     return maxi;
// }

// TWO POINTER APPROACH
int maxWater(vector<int> &vec) {

    int maxi = 0;
    int l = 0;
    int r = vec.size()-1;

    while (l<r) {
        int height = min(vec[l], vec[r]);
        int width = r-l;
        int water = height*width;
        maxi = max(maxi, water);
        if (vec[l] < vec[r]) {
            l++;
        }
        else {
            r--;
        }
    }

    return maxi;
}

int main () {
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxWater(vec) << " ";

    return 0;
}