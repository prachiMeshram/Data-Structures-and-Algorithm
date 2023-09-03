// https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
}

// linkedlist detect cycle approach

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    int slow = 0;
    int fast = 0;

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = 0;

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}
