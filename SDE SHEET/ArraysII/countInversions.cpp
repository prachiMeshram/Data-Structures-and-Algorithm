// https://www.codingninjas.com/studio/problems/count-inversions_615?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

long long getInversions(long long *arr, int n){
    // Write your code here. 
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                ans++;
            }
        }
    }

    return ans;
}

// using merge sort

#include <bits/stdc++.h> 

long long merge(long long *arr, int s, int e) {
    int cnt = 0;
    
    int m =  s + (e - s)/2;
    vector<int> temp;
    
    int l = s;
    int r = m+1;
    
    while (l <= m && r <= e) {
        if (arr[l] <= arr[r]) {
            temp.push_back(arr[l++]);
        }
        else {
            temp.push_back(arr[r++]);
            cnt += m-l+1;
        }
    }

    while (l <= m) {
        temp.push_back(arr[l++]);
    }
    while (r <= e) {
        temp.push_back(arr[r++]);
    }
    
    for (int i = s; i <= e; i++) {
        arr[i] = temp[i-s];
    }
    return cnt;
}

long long mergeSort(long long *arr, int s, int e) {
    long long cnt = 0;
    if (s >= e) return cnt;
    int mid =  s + (e - s)/2;
    cnt += mergeSort(arr, s, mid);
    cnt += mergeSort(arr, mid+1, e);
    cnt += merge(arr, s, e);

    return cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n-1);
}