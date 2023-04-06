// https://www.interviewbit.com/problems/find-nth-fibonacci/discussion/p/c-detailed-explanation-must-visit-matrix-exponetiation-fully-commented/276110/1955/

// Intutuion -: we use recursion which takes O(2^n) time , DP - O(n) time

// Now the constraint is n=10^15

// we need O(logn) solution

// fib(n)=fib(n-1) + fib(n-2)

//[f(n) ] -> [ 1, 1 ] [f(n-1)]
//[f(n-1)] -> [ 1 , 0] [f(n-2)]

// lets say this 2*2 matrix is A

// recursively we can write

//[f(n) ] -> [ 1, 1 ] ^(n-2) [f(2)]
//[f(n-1)] -> [ 1 , 0] [f(1)]

// we can break the Matrix A^n as -> A^n/2 * A^n/2 if nis even
// if nis odd A^n = A^(n/2) * A ^(n/2) * as

// we break it recursively and n-> n/2 -> n/4 -> n/8 -> n/16 -> n/32 i.e O(logn)

// then multiply the matrices , remember matrices multiplication will be of size k=2 ;

// matrix mutplication takes O(k^3) time but k=2 , i.e size of A matrix , constant time

// Total time complexity is O(k^3 * log(n))

#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

vector<vector<int>> matmul(vector<vector<int>> &a , vector<vector<int>> &b)
{
int n=a.size();
vector<vector<int>> ans(n , vector<int>(n , 0));
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
for(int k=0;k<n;k++)
{
ans[i][j]=(ans[i][j]%mod + (a[i][k]%mod * b[k][j]%mod)%mod)%mod;
}
}
}
return ans;
}

vector<vector<int>> matrix_exponentiation(vector<vector<int>> &A , int n)
{
if(n==0)
{
return {{1, 0} , {0 , 1}};
// A^0 i.e Identity matrix
}
if(n==1)
{
return A ;
}
vector<vector<int>> temp=matrix_exponentiation(A , n/2);
vector<vector<int>> multiplied_matrix=matmul(temp , temp);
if(n%2!=0)
{
multiplied_matrix=matmul(multiplied_matrix , A);
}
return multiplied_matrix;
}



int solve(int n) {
vector<vector<int>> A ={{1, 1} , {1 , 0}};
vector<vector<int>> fib=matrix_exponentiation( A , n);
return fib[1][0];

//as fib[0][0]=fib(n+1)
// fib[0][1]=fib[1][0]=fib(n);
// fib[1][1]=fib(n-1)

// thses are the values i got , when i run this code on VS code
// so by  fib(n) was coming on fib[1][0] and fib[0][1]
}