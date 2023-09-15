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

// same as above but with OPTIMAL RUNTIME
/*
    Time Complexity: O(N * log(N)).
    Space Complexity: O(N).

    Where 'N' is the number of meetings.
*/

struct meet
{
    int meetingID;
    int startTime;
    int endTime;
};

bool compare(struct meet a, struct meet b)
{
    if (a.endTime == b.endTime)
    {
        return a.meetingID < b.meetingID;
    }
    else
    {
        return a.endTime < b.endTime;
    }
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    // Creating meeting array of size N.
    struct meet meeting[n];

    for (int i = 0; i < n; i++)
    {
        meeting[i].meetingID = i + 1;
        meeting[i].startTime = start[i];
        meeting[i].endTime = end[i];
    }

    // Sorting the meeting array in increasing order of end time using customized comparator.
    sort(meeting, meeting + n, compare);

    // Taking the first meeting of sorted array as our first meeting.
    int ans = 1;
    int currentTime = meeting[0].endTime;

    for (int i = 1; i < n; i++)
    {
        // If startTime of current meeting is greater than our currentTime.

        // Then we will perform this meeting and update currentTime with endTime of the meeting.
        if (meeting[i].startTime > currentTime)
        {
            ans++;
            currentTime = meeting[i].endTime;
        }
    }

    return ans;
}
