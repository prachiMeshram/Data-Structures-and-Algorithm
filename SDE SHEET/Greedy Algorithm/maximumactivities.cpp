// https://www.codingninjas.com/studio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

struct activity {
    int e;
    int s;
    int ind;
};

bool compare(activity &a1, activity &a2) {
    if (a1.e < a2.e) return true;
    else if (a1.e > a2.e) return false;
    else if (a1.ind < a2.ind) return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    struct activity a[n];

    for (int i = 0; i < n; i++) {
        a[i].e = finish[i]; 
        a[i].s = start[i]; 
        a[i].ind = i; 
    }
    sort(a, a+n, compare);

    int maxiActivity = 1;
    int lastFin = a[0].e;

    for (int i = 1; i < n; i++) {
        if (a[i].s >= lastFin) {
            maxiActivity++;
            lastFin = a[i].e;
        }
    }
    return  maxiActivity;
}