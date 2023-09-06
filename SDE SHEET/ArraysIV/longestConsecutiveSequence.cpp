// https://www.codingninjas.com/studio/problems/759408?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// brute force
bool linearSearch(vector<int> &a, int num) {
    for (auto it: a) {
        if (num == it) {
            return true;
        }
    }
    return false;
}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int cnt = 1;

        while (linearSearch(arr, x+1) == 1) {
            x += 1;
            cnt += 1;
        }
        ans = max(ans, cnt);
    }

    return ans;
}

// better approach using sorting
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if (n == 0) {
        return 0;
    }
    sort(arr.begin(), arr.end());
    int lastSmallest = INT_MIN;
    int longest = 1;
    int cnt = 0;
    
    for ( int i = 0; i < n; i++) {
        if (arr[i]-1 == lastSmallest) {
            lastSmallest = arr[i];
            cnt++;
        }
        else if (arr[i] != lastSmallest) {
            lastSmallest = arr[i];
            cnt = 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// optimal approach
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if (n == 0) {
        return 0;
    }
     
    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }
    
    for (auto it: st) {
        
        if (st.find(it-1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                cnt++;
                x++;
            } 
            longest = max(longest, cnt);
        }
    }
    return longest;
}