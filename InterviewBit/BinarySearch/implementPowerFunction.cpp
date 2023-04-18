// https://www.interviewbit.com/problems/implement-power-function/discussion/p/convert-power-into-binary-c-easy-solution/379803/773/

#include<bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
       if (x == 0 || d == 1) {
           return 0;
       }
       if (x == 1 || n == 0) {
           return 1;
       }
       
       int ans = 1;
       int y = x;
       int z = n;
       x = abs(x);
       while (n) {
           if (n&1) {
               ans = (1ll*x*ans)%d;
           }
           n =  n>>1;
           x = (1ll*x*x)%d;
       }
       if (y<0 && z&1) {
           ans = abs(abs(ans)-d);
       }
       return ans;
}
    
