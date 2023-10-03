// https://www.codingninjas.com/studio/problems/selection-sort_624469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr) {
    // Write your code here.
    int n = arr.size();

    for (int i = 0; i < n-1; i++) {
        int mini = i;
        for (int j = i+1; j < n; j++) {
            if (arr[mini] > arr[j]) {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}