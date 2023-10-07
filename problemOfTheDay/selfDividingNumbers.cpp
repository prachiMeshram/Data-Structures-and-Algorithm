// https://www.codingninjas.com/studio/problems/self-dividing-numbers_1462445?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
bool isPossible (int n) {
    int num = n;
    while (num!=0) {
        int digit = num%10;
        
        if (digit == 0 || n%digit != 0) {
            return false;
        }
        num = num/10;
    }
    return true;
}
vector < int > findAllSelfDividingNumbers(int lower, int upper) {
    // Write your code here
    vector<int> ans;
    
    for (int i = lower; i <= upper; i++) {
        if (i < 10) {
            ans.push_back(i);
        }
        else {
            if (isPossible (i)) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}