// https://www.codingninjas.com/codestudio/problem-of-the-day/moderate

#include <bits/stdc++.h> 
using namespace std;

vector<int> specialSubarray(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;

    int maxi = INT_MIN;
    for(int j = 0; j < n; j++) {
        if (arr[j]>maxi) {
            maxi = arr[j];
        }
    }
    // cout<<"maxi: "<<maxi<<endl;
    int m = maxi+1;
    vector<int> count(m, 0);
    
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int freqNum = 0;
    int freq = count[0];
    for(int j = 0; j < m; j++) {
        if (count[j]>freq) {
            freq = count[j];
            freqNum = j;
        }
    }

    
    // start index


    int s = 0;
    while (arr[s] != freqNum) {
        s++;
    }
    int e = n-1;
    while (arr[e]!=freqNum) {
        e--;
    }

    for (int i = s; i<=e; i++) {
        ans.push_back(arr[i]);
    }

    return ans;
}