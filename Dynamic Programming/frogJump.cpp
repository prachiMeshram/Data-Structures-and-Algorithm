#include<bits/stdc++.h>
using namespace std;

// recursion
int frogJumps(int index, vector<int> &arr) {
    // base case
    if (index == 0) {
        return 0;
    }

    // left 
    int left = frogJumps(index-1, arr) + abs(arr[index] - arr[index-1]);
    // right
    int right = INT_MAX;
    if (index > 1) {
        right = frogJumps(index - 2, arr) + abs(arr[index] - arr[index-2]);
    }

    return min(left, right);

}

int main () {

// int n;
// cin >> n;

vector<int> arr{ 10, 20, 30, 10 };
// for (int i = 0; i < n; i++) {
//     cin >> arr[i];
// }

cout << frogJumps(3, arr) << " ";
}