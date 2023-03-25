/*You are given an array 'STRINGS' having 'N' number of strings. The strings are assumed to be arranged such that there is one string in one line.
You need to return the number of columns that are not sorted lexicographically.*/


#include <bits/stdc++.h> 
using namespace std;

int countColumns(vector<string> &strings)
{
    // Write your code here.
    int count = 0;
    int N = strings[0].size();

    for (int j = 0; j < N; j++) {
        for (int i = 1; i < strings.size(); i++) {
            if (strings[i-1][j] > strings[i][j]) {
                count++;
                break;
            }
        }
    }
    return count;
}
