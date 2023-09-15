// https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<int> AT;
    for (int i = 0; i < n; i++) {
        AT.push_back(at[i]);
    } 
    vector<int> DT;
    for (int i = 0; i < n; i++) {
        DT.push_back(dt[i]);
    } 
    
    sort(AT.begin(), AT.end());
    sort(DT.begin(), DT.end());
    
    int plat = 1;
    int maxi = 1;
    
    int i = 1;
    int j = 0;
    
    while (i<n) {
        if (AT[i] <= DT[j]) {
            plat++;
            i++;   
        }
        else {
            plat--;
            j++;
        }
        maxi = max(maxi, plat);
    }

    return maxi;
}