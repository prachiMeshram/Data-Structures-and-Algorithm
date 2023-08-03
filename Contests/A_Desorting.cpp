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
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (!is_sorted(arr.begin(), arr.end())) {
            cout << 0 << endl;
        }
        else {
            int mini = INT_MAX;

            for (int i = 1; i < n; i++) {
                if (arr[i] - arr[i-1] < mini) {
                    mini = arr[i] - arr[i-1];
                }
            }
            cout << mini/2 + 1 << endl;
        }

        
    }

    return 0;
}