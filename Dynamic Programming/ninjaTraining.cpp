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

int ninjaTrainingTabulation(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    // return maxPoints(n-1, 3, dp, points);

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]) );

    for (int day=1; day<n; day++) {
        for (int last = 0; last < 4; last++) {
            // int maxi = 0;
            for (int task=0; task<3; task++) {
                if (task != last) {
                    int pts = points[day][task] + dp[day-1][task];
                    // maxi = max(maxi, pts);
                    dp[day][last] = max(dp[day][last], pts);
                }
            }
            // dp[day][last] = maxi; 
        }
    }

    return dp[n-1][3];
}