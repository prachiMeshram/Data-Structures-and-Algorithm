//  https://www.interviewbit.com/problems/all-factors/

#include<bits/stdc++.h>
using namespace std;

vector<int> allFactors(int A) {
    vector<int> ans;
    vector<int> ans2;
    for(int i=1;i*i<=A;i++){
        if(A%i==0){
            if(i!=A/i){
                ans.push_back(i);
                ans2.push_back(A/i);
            }else{
                ans.push_back(i);
            }
        }
    }
    reverse(ans2.begin(),ans2.end());
    for(auto i:ans2){
        ans.push_back(i);
    }
    return ans;
}
