// https://www.interviewbit.com/problems/merge-overlapping-intervals/

// [ (5, 28), (7, 70), (54, 93), (5, 98), (46, 70), (42, 63), (5, 91), (30, 49), (36, 57), (31, 95), (86, 88), (9, 90), (5, 53), (42, 62), (14, 100), (59, 75), (32, 100), (5, 79), (31, 31), (7, 42), (13, 47), (44, 87), (61, 83), (100, 100), (96, 98), (47, 51), (34, 44), (6, 53), (30, 92), (50, 64), (37, 57), (49, 67), (2, 67), (36, 50), (55, 100), (54, 78), (58, 70), (2, 37), (13, 54), (7, 60), (16, 79), (35, 78), (17, 57), (16, 84), (60, 80), (10, 54), (54, 59), (62, 85), (7, 37), (31, 99), (40, 41), (4, 99), (28, 45), (27, 71), (14, 64) ]
// The expected return value: 
// (2, 100) 
// Your function returned the following: 
// (2, 100) (100, 100) 

#include <bits/stdc++.h>
using namespace std;

// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

vector<Interval> merge(vector<Interval> &A) {
    
    sort(A.begin(),A.end(),[](Interval i1,Interval i2){
        return i1.start<i2.start;
    });
    
    vector<Interval> ans;
    
    Interval temp; 
    temp.start = A[0].start;
    temp.end = A[0].end;
    
    int i = 1;
    while (i < A.size()) {
        if (temp.end>=A[i].start) {
            // temp.start = min(temp.start, A[i].start);
            temp.end = max(temp.end, A[i].end);
        }
        else {
            ans.push_back(temp);
            temp.start = A[i].start;
            temp.end = A[i].end;
        }
        i++;
    }
    
    ans.push_back(temp);
    
    return ans;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
