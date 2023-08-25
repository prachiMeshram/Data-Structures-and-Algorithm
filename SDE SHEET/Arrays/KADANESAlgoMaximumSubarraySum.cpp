// https://www.codingninjas.com/studio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long maxi = LONG_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0) {
            sum = 0;
        }
    }

    if (maxi < 0) {
        return 0;
    }
    else {
        return maxi;
    }
    
}