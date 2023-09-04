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

// two pointer approach
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(), book.end());
    
    int s = 0;
    int e = n-1;
    
    while (s <= e) {
        int sum = book[s] + book[e];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) {
            s++;
        }
        else {
            e--;
        }
    }

    return "NO";
}
