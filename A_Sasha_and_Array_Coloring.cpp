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


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    // cout << "total testCases: " << t << endl << endl;

    for (int i = 0; i < t; i++) {

        int n;
        cin >> n;

        int a[n];

        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }

        sort(a, a + n);
        int ans = 0;

        int s = 0;
        int e = n-1;
        

        while (s<=e) 
        {
            // cout << s << e << " " << a[s] << "   " << a[e] << endl;
            ans += a[e] - a[s];
            e--;
            s++;
        }

        cout << ans << endl;
    }

    return 0;
}