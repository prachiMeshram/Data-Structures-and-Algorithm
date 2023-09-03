// https://www.codingninjas.com/studio/problems/find-x-raised-to-power-n-_626560?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
using namespace std;

// Binary Exponentiation
double myPow(double x, int n) {
    // Write Your Code Here
    double ans = 1.0;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
        if (nn % 2) {
            ans = ans*x;
            nn = nn - 1;
        }
        else {
            x = x*x;
            nn /= 2;  
        }
    }
    if (n < 0) {
        ans = (double)(1.0)/(double)(ans);
    }
    return ans;
}