// https://www.codingninjas.com/studio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// OPTIMAL APPROACH
bool isPossible(long long mid, vector<int> &time, int n, int m) {
    int dayCount = 1; 
    long long timeSum = 0;

    for (int i = 0; i < m; i++) {
        if (timeSum + time[i] <= mid) {
            timeSum += time[i];
        }
        else {
            dayCount++;
            if (dayCount > n || time[i] > mid) {
                return false;
            }
            timeSum = time[i];
        }
    }

    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long ans = -1;
    long long s = 0;
    long long e = 0;

    for (int i = 0; i < m; i++) {
        e += time[i];
        s = max((long long)time[i], s);
    }
    
    while (s <= e) {
        
        long long mid = s + (e-s)/2;
        if (isPossible (mid, time, n, m)) {
            ans = mid; 
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }

    return ans;
}

// BRUTE FORCE
#include <bits/stdc++.h> 
bool isPossible(long long mid, vector<int> &time, int n, int m) {
    int dayCount = 1; 
    long long timeSum = 0;

    for (int i = 0; i < m; i++) {
        if (timeSum + time[i] <= mid) {
            timeSum += time[i];
        }
        else {
            dayCount++;
            if (dayCount > n || time[i] > mid) {
                return false;
            }
            timeSum = time[i];
        }
    }

    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long ans = -1;
    long long s = 0;
    long long e = 0;

    for (int i = 0; i < m; i++) {
        e += time[i];
        s = max((long long)time[i], s);
    }

    for (int i = s; i <= e; i++) {
        if (isPossible (i, time, n, m)) {
            return i; 
        }
    }
    
    return ans;
}