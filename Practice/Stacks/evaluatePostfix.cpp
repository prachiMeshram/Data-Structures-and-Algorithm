#include<bits/stdc++.h>
using namespace std;


const long long int N = 1e6+2;
const long long int MOD = 1e9+7;

#define F	first
#define S	second
#define pb	push_back
#define POB	pop_back
#define MP	make_pair
#define ump	unordered_map
#define int	long long int
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pi;

int solve(string &s) {
    stack<int> st;

    for (char ch: s ) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int first = st.top();
            st.pop();
            int sec = st.top();
            st.pop();

            if (ch == '+') {
                st.push(first+sec);
            }
            else if (ch == '-') {
                st.push(sec-first);
            }
            else if (ch == '*') {
                st.push(first*sec);
            }
            else if (ch == '/') {
                st.push(sec/first);
            }

        }
        else {
            st.push(ch - '0');
        }
    }
    return st.top();
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // string : 23+54*-
    string  s = "23+54*-";

    int ans = solve(s);
    cout << ans; 

    return 0;
}