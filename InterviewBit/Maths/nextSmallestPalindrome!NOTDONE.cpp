// https://www.interviewbit.com/problems/next-smallest-palindrome/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string temp) {
  int s = 0; 
  int e = temp.size()-1;
  while (s<e) {
    if (temp[s]!=temp[e]) {
      return 0;
    }
    s++;
    e--;
  }
  return 1;
}

string solve(string A) {
    string res;
    
    int num = stoi(A);
    cout << num <<endl; 
    
    bool isNine = true;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != '9') {
            isNine = false;
            break;
        }
    }
    cout <<"isNine "<< isNine << endl;
    
    if (isNine == true) {
        res = to_string(num+2);
        return res;
    }
    else {
        int s = 0; 
        int e = A.size()-1;
        int temp = num;
        int tempS = to_string(temp);
        while (s<e || isPalindrome(tempS)==0) {
            tempS[e] = tempS[s];
        }
        tempS[s] = tempS+1;
        return tempS;
    }
    
}




//    CODE NOT WORKING 
// bool isPalindrome(string temp) {
//   int s = 0; 
//   int e = temp.size()-1;
//   while (s<e) {
//     if (temp[s]!=temp[e]) {
//       return 0;
//     }
//   }
//   return 1;
// }

// string Solution::solve(string A) {
//     string res;
//     int n = A.size();
    
//     int num = stoi(A);
    
//     int temp = num+1;
//     string tempS = to_string(temp);
//     int i = 2;
//     while (isPalindrome(tempS) ==0 ) {
//         tempS = to_string(temp+i);
//         i++;
//     }

//     return tempS;
// }