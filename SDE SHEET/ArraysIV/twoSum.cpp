// https://www.codingninjas.com/studio/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    map<int, int> mpp;
    for (int i = 0; i < n ; i++) {
        int sec = target-book[i];
        if (mpp.find(sec) != mpp.end()) {
            return "YES";
        }
        else {
            mpp[book[i]] = i;
        }
    }

    return "NO";
}
