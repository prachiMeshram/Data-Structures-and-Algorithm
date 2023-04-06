// https://www.interviewbit.com/problems/palindrome-integer/

#include<bits/stdc++.h>;
using namespace std;

int isPalindrome(int A) {
    if (A<0) {
        return 0;
    }
    
    int rev = 0;
    int num = A;
    while (num!=0) {
        int digit = num%10;
        rev = rev*10 + digit;
        num = num/10;
    }
    
    // cout << rev << endl;
    
    if (rev == A) {
        return 1;
    }
    else {
        return 0;
    }
}

// with xtra space

// int isPalindrome(int A) {
//     string a = to_string(A);
//     int s = 0; 
//     int e = a.size()-1;
    
//     while (s<e) {
//         if(a[s]!=a[e]) {
//             return 0;
//         }
//         s++;
//         e--;
//     }
    
//     return 1;
// }
