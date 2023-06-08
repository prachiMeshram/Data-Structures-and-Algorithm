#include <bits/stdc++.h>
using namespace std;

bool sortCol (const vector<int> &v1, const vector<int> &v2) {
    return v1[2] < v2[2];
}

int main () {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    int size = start.size();

    vector<vector<int>> activities (size, vector<int>(3,0));

    for (int i = 0; i < size; i++) {
        activities[i][0] = i;
        activities[i][1] = start[i];
        activities[i][2] = end[i];
    }

    sort(activities.begin(), activities.end(), sortCol);

    // endTime basis sorted
    int maxAct = 0;
    vector<int> ans;

    // 1st activity
    maxAct = 1;
    ans.push_back(activities[0][0]);
    int lastEnd = activities[0][2];
    for (int i = 1; i < end.size(); i++) {
        if (activities[i][1] >= lastEnd) {
            // select this activity
            maxAct++;
            ans.push_back(activities[i][0]);
            lastEnd = activities[i][2];
        }
    }

    cout << maxAct << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "A" << ans[i] << " ";
    }

    return 0;
}

// int main () {

//     vector<int> start = {1, 3, 0, 5, 8, 5};
//     vector<int> end = {2, 4, 6, 7, 9, 9};

//     // SORTED ON THE BASIS OF ENDTIME 
//     int maxAct = 0;
//     vector<int> ans;

//     // 1st activity
//     maxAct = 1;
//     ans.push_back(0);
//     int lastEnd = end[0];
//     for (int i = 0; i < end.size(); i++) {
//         if (start[i] >= lastEnd) {
//             // select this activity
//             maxAct++;
//             ans.push_back(i);
//             lastEnd = end[i];
//         }
//     }

//     cout << maxAct << " ";

//     return 0;
// }