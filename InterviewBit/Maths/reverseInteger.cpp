// https://www.interviewbit.com/problems/reverse-integer/

#include<bits/stdc++.h>
using namespace std;

int reverse(int A) {
    
    int num = abs(A);
    int res = 0;
    
    while (num != 0) {
        int digit = num%10;
        if (res>=INT_MAX/10) {
            return 0;
        }
        res = res*10 + digit;
        num = num/10;
    }
    if (A<0) {
        return -1*res;
    }
    if (res>=INT_MAX || res<=INT_MIN) {
        return 0;
    }
    return res;
}
