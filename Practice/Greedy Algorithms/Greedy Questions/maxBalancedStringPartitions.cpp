// We have balanced string str of size N with an equal number of L and R,the task is to find a maximum number X,such that a given string can be partitioned into X balanced substring. A string is called to be balanced if the number of ‘L’s in the string equals the number of ‘R’s

#include<bits/stdc++.h>
using namespace std;

int main () {

    vector<char> str{'L','R', 'R', 'R', 'R', 'L', 'L', 'R', 'L', 'L', 'R', 'L'};

    if (str.size() == 0) {
        return 0;
    }

    int ans = 0;
    int r = 0;
    int l = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'R') {
            r++;
        }
        else if (str[i] == 'L') {
            l++;
        }

        if (r == l) {
            ans++;
        }
    }

    cout << ans << " ";

    return 0;
}