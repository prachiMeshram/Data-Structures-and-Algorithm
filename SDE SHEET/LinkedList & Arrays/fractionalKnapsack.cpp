// https://www.codingninjas.com/studio/problems/fractional-knapsack_975286?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    return ((double)(p1.second)/p1.first > (double)(p2.second)/p2.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), compare);

    double maxVal = 0;
    int capacity = w;
    
    for (int i = 0; i < n; i++) {
        if (items[i].first <= capacity) {
            maxVal += items[i].second;
            capacity -= items[i].first;
        }
        else {
            if (capacity != 0) {
                maxVal += capacity*((double)(items[i].second)/items[i].first);
            }
            break;
        }
    }
    return maxVal;
}