#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            }
            else {
                ans += count*(count+1)/2;
                count = 0;
            }
        } 
    return ans += count*(count+1)/2;


// n = 8;

//         long long ans = 0;
//         int i = 0; 

//  // [0,1,0,0,1,0,0,0]
//         while (i < nums.size()) {
//             cout << i<< " ";
//             if (nums[i]!=0) {
//                 i++;
//             }
//             else {
//                 long long temp = 0;
//                 while (nums[i]==0 && i<nums.size()) {
//                     temp++;
//                     i++;
//                 }
//                 ans += temp*(temp+1)/2; 
//             }
//         }
//         return ans;
    }
};