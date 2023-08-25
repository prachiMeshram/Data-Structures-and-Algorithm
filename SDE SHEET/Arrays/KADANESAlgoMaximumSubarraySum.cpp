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

// to print subarray of maximum sum
#include <bits/stdc++.h> 
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

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {

        if (sum == 0) {
            start = i; // starting index
        }

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }
        
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "the subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";
}