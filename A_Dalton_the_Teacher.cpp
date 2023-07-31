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

    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int count = 0; 

        for (int i = 0; i < n; i++) {
            if(p[i] - 1 == i ) {
                count++;
            }
        }
        if (count%2 == 0) {
            cout << count/2 << endl; 
        }
        else {
            cout << count/2 + 1 << endl;
        }
         
    }

    return 0;
}