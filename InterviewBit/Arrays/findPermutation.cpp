// https://www.interviewbit.com/problems/find-permutation/discussion/p/easy-c-solution-o-n-t-c-and-o-n-s-c/375442/1012/

#include<bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int B) {
     int n=B;
    vector<int> v;
    int gre=B, sma=1;
    if(A[0]=='D'){
            v.push_back(gre);
            gre--;
        }
        else if(A[0]=='I'){
            v.push_back(sma);
            sma++;
        }
    for(int i=1;i<n-1;i++){
        if(A[i]=='D'){
            v.push_back(gre);
            gre--;
        }
        else if(A[i]=='I'){
            v.push_back(sma);
            sma++;
        }
    }
    // if(A[n-1-1]=='D'){
    //         v.push_back(gre);
    //         gre--;
    //     }
    //     else if(A[n-1-1]=='I'){
    //         v.push_back(sma);
    //         sma++;
    //     }
    
    v.push_back(gre);
   
    return v;
}

