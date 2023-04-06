// https://www.interviewbit.com/problems/addition-without-summation/

#include<bits/stdc++.h>
using namespace std;

int addNumbers(int A, int B) {
    while (B) {
        unsigned carry = A&B;
        A = A^B;
        B = carry << 1;
    }
    return A;
}



// int Solution::addNumbers(int A, int B) {
//     if (A == 0) {
//         return B;
//     }
//     if (B == 0) {
//         return A;
//     }
    
//     return  addNumbers(A^B, 2*(A&B));
    
//     // Because you can always write A+B = A^B + 2*(A&B)
// }
