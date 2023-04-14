// https://www.interviewbit.com/problems/painters-partition-problem/discussion/p/c-solution-using-binary-search-code-only/264833/903/

#include<bits/stdc++.h>
using namespace std;


#define ll long long 

bool isPossible(int A, vector<ll> &a, ll mid, int N) {
    ll painterNo = 1;
    ll time = 0;
    for (int i = 0; i < N; i++) {
        if (time + a[i] <= mid) {
            time += a[i];
        }
        else {
            painterNo++;
            if (painterNo > (1LL*A)) {
                return false;
            }
            time = a[i];
        }
    }
    return true;
}   

int paint(int A, int B, vector<int> &C) {
    // A: no of painters
    // B: time take by each painter to paunt 1 unit board
    // C[i] represents the length of ith board.
    
    ll M = 1e7+3;
    
    int N = C.size();
    
    vector<ll> a(N);
    ll st = 1, end;
    for (int i = 0; i < N; i++) {
        a[i] = 1LL*B*C[i];
        end += a[i]; 
        st = max(st,a[i]);
    }
    
    
    ll s = st;
    ll e = end;
    ll ans;
    
    while (s<=e) {
        ll mid = s + (e-s)/2;
        if (isPossible(A, a, mid, N)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return ans%M;
}
