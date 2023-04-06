// https://www.interviewbit.com/problems/grid-unique-paths/discussion/p/c-both-recursive-and-iterative-method-solution/284769/527/

#include<bits/stdc++.h>
using namespace std;


int uniquePaths(int A, int B) {
    //WITHOUT RECURSION
    
    // if(A<B){
    //     swap(A,B);
    // }
    // vector<int> vec(A,1);
    // for(int i =1; i<B; i++){
    //     for(int j=1; j<A; j++){
    //         vec[j] += vec[j-1];
    //     }
    // }
    // return vec[A-1];
    
    
    // WITH RECURSION
    if(A==1 || B==1) return 1;
    int ans = uniquePaths(A-1,B)+uniquePaths(B-1,A);
    return ans;
}




// MY APPROACH

// void countPath(int A, int B, vector<vector<int>> &visited, int x, int y, int &ans) {
//     if(x == A-1 && y == B-1) {
//         ans++;
//         return;
//     }
    
//     visited[x][y] = 1;
//     // down
//     int newx = x+1;
//     int newy = y;
//     if (visited[newx][newy] == 0 && newx<A) {
//         countPath(A, B, visited, newx, newy, ans);
//     }
    
//     // right
//     newx = x;
//     newy = y+1;
//     if (visited[newx][newy] == 0 && newy<B) {
//         countPath(A, B, visited, newx, newy, ans);
//     }
    
//     visited[x][y] = 0;
// }

// int Solution::uniquePaths(int A, int B) {
//     int srcx = 0;
//     int srcy = 0;
//     int ans = 0;
    
//     vector<vector<int>> visited( A , vector<int> (B, 0)); 
    
//     countPath(A, B, visited, srcx, srcy, ans);
    
//     return ans;
// }
