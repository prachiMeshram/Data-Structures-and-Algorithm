#include <iostream>
#include <vector>
using namespace std;


vector<int> plusOne(vector<int> &A) {
    vector<int> a;
    
    for (int i = 0; i < A.size(); i++) {
        a.push_back(A[i]);
    }
    
    int carry = 1;
    for(int i = A.size()-1; i>0; i--) {
        if (a[i] + carry == 10) {
            a[i] = 0;
            carry = 1;
        }
        else {
            a[i] = a[i] + carry;
            carry = 0;
        }
    }
    
    if (a[0]+carry == 10) {
        a[0] = 0;
        a.insert(a.begin(),1);
    }
    else {
        a[0] = a[0] + carry;
        // make sure that there are no zeros at the beginning
        while (a[0]==0) {
            a.erase(a.begin());
        }
    }
    
    return a;
    
    // vector<int> ans;
    
    // int i = A.size()-1;
    // int carry = 1;
    // int sum = A[i] + carry;
    
    // if (sum == 10) {
    //     carry = 1;
    //     ans.push_back(0);
    //     i--;
    // }
    // // [ 1,9,9,9,9]
    // // [ 9,9,9,9]
    
    // while (i>=0) {
    //     sum = A[i] + carry;
    //     if (sum == 10) {
    //         ans.push_back(0);
    //         carry = 1;
    //         i--;
    //     }
    //     else {
    //         ans.push_back(sum);
    //         i--;
    //         break;
    //     }
        
    // }
    
    // while (i>=0) {
    //     ans.push_back(A[i]);
    // }
    
    // int s = 0; 
    // int e = ans.size()-1;
    // while (s<=e) {
    //     swap(ans[s++],ans[e--]);
    // }
    // return ans;
    
    // int temp = 0;
    // vector<int> ans;
    
    // for (int i = 0; i < A.size(); i++) {
    //     temp += A[i]*(10^i); 
    // }
    // temp += 1;
    
    // while (temp!=0) {
    //     int digit = temp%10;
    //     ans.push_back(digit);
    //     temp = temp/10;
    // }
    // int s = 0; 
    // int e = ans.size()-1;
    // while (s<=e) {
    //     swap(ans[s++],ans[e--]);
    // }
    // return ans;
}
