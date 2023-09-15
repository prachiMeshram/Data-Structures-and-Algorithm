// https://www.codingninjas.com/studio/problems/maximum-meetings_1062658?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();

    vector<vector<int>> meet; // vector<{end,start}>
    
    for (int i = 0; i < n; i++) {
        vector<int> temp = {end[i], start[i]};
        meet.push_back(temp);
    }
    
    sort(meet.begin(), meet.end());
    int lastEnd = meet[0][0];
    int totMeets = 1;
    for (int i = 1; i < n; i++) {
        if (meet[i][1] > lastEnd) {
            lastEnd = meet[i][0];
            totMeets++;
        }
        else {
            continue;
        }
    }
    return totMeets;
}