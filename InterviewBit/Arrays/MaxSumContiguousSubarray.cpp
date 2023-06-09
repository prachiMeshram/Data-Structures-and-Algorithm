#include<iostream>
#include<vector>;
using namespace std;


int maxSubArray(const vector<int> &A) {
    int sum = 0;
    int maxSum = A[0];
    for(int i = 0; i<A.size(); i++){
        sum += A[i];
        maxSum = max(maxSum,sum);
        if(sum<0){
            sum = 0;
        }
    }
    return maxSum;
}
