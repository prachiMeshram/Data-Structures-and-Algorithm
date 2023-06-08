#include<bits/stdc++.h>
using namespace std;

int main () {
    int n = 3;
    int k = 42;
    vector<char> ans;

    for (int i = 26; i >= 1; i++) {
        char letter = 'a' + 25;
        while (k > i) {
            k -= i;
            ans.push_back(letter);
        }
        if (k == 0) {
            break;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}