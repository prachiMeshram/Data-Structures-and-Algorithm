// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;


int maxPoints(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &points) {
    if ( day == 0 ) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    } 

    if (dp[day][last] != -1) {
        return dp[day][last];
    }
    
    int maxi = 0;

    for (int task = 0; task < 3; task++) {
        if (task!=last) {
            int pts = points[day][task] + maxPoints(day-1, task, dp, points);
            maxi = max(maxi, pts);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    return maxPoints(n-1, 3, dp, points);

}