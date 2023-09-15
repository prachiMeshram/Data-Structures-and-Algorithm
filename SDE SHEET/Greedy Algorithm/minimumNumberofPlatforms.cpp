// https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    vector<int> AT;
    for (int i = 0; i < n; i++)
    {
        AT.push_back(at[i]);
    }
    vector<int> DT;
    for (int i = 0; i < n; i++)
    {
        DT.push_back(dt[i]);
    }

    sort(AT.begin(), AT.end());
    sort(DT.begin(), DT.end());

    int plat = 1;
    int maxi = 1;

    int i = 1;
    int j = 0;

    while (i < n && j < n)
    {
        if (AT[i] <= DT[j])
        {
            plat++;
            i++;
        }
        else
        {
            plat--;
            j++;
        }
        maxi = max(maxi, plat);
    }

    return maxi;
}
// using frequency arrya
/*
    Time Complexity : O(N * 2360)
    Space Complexity : O(1)

    Where 'N' is the number of trains.
*/

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Array to store the number of platforms required at different points of time.
    int platforms[2360] = {0};

    // Variable to store the final answer i.e. minimum number of platforms required.
    int minNumOfPlatforms = 1;

    for (int i = 0; i < n; i++)
    {
        // Increment number of platforms for all times between arrival and departure (both inclusive).
        for (int j = at[i]; j <= dt[i]; j++)
        {
            platforms[j]++;

            // Update minimum number of platforms.
            minNumOfPlatforms = max(minNumOfPlatforms, platforms[j]);
        }
    }

    // Return the minimum number of platforms.
    return minNumOfPlatforms;
}

// using cumulative sum
/*
    Time Complexity : O(N)
    Space Complexity :  O(1)

    Where 'N' is the number of trains.
*/

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Array to store the number of platforms required at different points of time.
    int platforms[2361] = {0};

    // Variable to store the final answer i.e. minimum number of platforms required.
    int minNumOfPlatforms = 1;

    for (int i = 0; i < n; i++)
    {

        // Increment the count of platforms at the time of arrival.
        ++platforms[at[i]];

        // Decrease the platform count just after the departure.
        --platforms[dt[i] + 1];
    }

    // We are running loop till 2361 because maximum time value in a day can be 23:60.
    for (int i = 1; i < 2361; i++)
    {

        // Taking cumulative sum of platforms.
        platforms[i] = platforms[i] + platforms[i - 1];

        // Update minNumOfPlatforms.
        minNumOfPlatforms = max(minNumOfPlatforms, platforms[i]);
    }

    // Return the minimum number of platforms.
    return minNumOfPlatforms;
}