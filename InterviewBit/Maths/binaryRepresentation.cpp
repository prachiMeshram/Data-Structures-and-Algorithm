// https://www.interviewbit.com/problems/binary-representation/

#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/binary-representation/

string findDigitsInBinary(int A) {
    string ans;
     
    if (A == 0) {
        return "0";
    }
    
    int n = A;
    int temp = 0;
    int base = 2;
    
    int i = 0;
    while (n!=0) {
        int rem = n%base;
        
        ans = to_string(rem) + ans;
        
        n = n/base;
    }

    return ans;
}


// string findDigitsInBinary(int A) {
//     string ans;
//     if (A == 0) {
//         return "0";
//     }
    
//     int n = A;
    
//     int i = 0;
//     while (n!=0) {
//         if (n&1) {
//             ans = "1" + ans;
//         }
//         else {
//             ans = "0" + ans;
//         }

//         n = n>>1;
//     }

//     return ans;
// }

// string Solution::findDigitsInBinary(int A) {
//     string ans;
     
//     if (A == 0) {
//         return "0";
//     }
    
//     int n = A;
//     int temp = 0;
    
//     int i = 0;
//     while (n!=0) {
//         int bit = n&1;
        
//         temp = (bit*pow(10, i)) + temp;
//         n = n>>1;
//         i++;
//     }
//     ans = to_string(temp);

//     return ans;
// }

