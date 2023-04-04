// https://www.interviewbit.com/problems/largest-number/


#include<bits/stdc++.h>
using namespace std;

string largestNumber(const vector<int> &A) {
    vector<string> temp;
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        temp.push_back(to_string(A[i]));
    }
    
    sort(temp.begin(), temp.end(), [&] (string a, string b) {
        return a+b > b+a;
    });
    
    string res = "";
    
    for (int i= 0; i < temp.size(); i++) {
        res += temp[i];
    } 
    
    if (temp[0] == "0") {
        return "0";
    }
    
    return res;
}




// vector<int> digitizer (int num) {
//     vector<int> ans;
    
//     while (num != 0) {
//         int digit = num%10;
//         ans.push_back(digit);
//         num = num/10;
//     }
    
//     int s = 0; 
//     int e = ans.size()-1;
//     while(s<e) {
//         swap(ans[s++],ans[e--]);
//     }
    
//     return ans;
// }

// string Solution::largestNumber(const vector<int> &A) {
//     vector<vector<int>> digitNum;
    
//     for (int i = 0; i < A.size(); i++) {
//         digitNum = digitizer(A[i]);
//     }
// }