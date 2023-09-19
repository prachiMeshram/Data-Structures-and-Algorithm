// https://www.codingninjas.com/studio/problems/630450?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int search(int* arr, int n, int key) {
    // Write your code here.
    int s = 0;
    int e = n-1;

    while (s <= e) {
        int mid = s + (e-s)/2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[s] <= arr[mid]) {
            if (arr[s] <= key && key <= arr[mid]) {
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        else {
            if (arr[mid] <= key && key <= arr[e]) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
    }

    return -1;
}