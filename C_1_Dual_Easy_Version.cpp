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

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // for all neg

        int countNeg = 0;
        for (auto it: arr) {
            if (it <= 0) {
                countNeg++;
            }
        }

        if (countNeg == n) {
            cout << n - 1 << endl;
            for (int i = n-1; i > 0; i--) {
                arr[i-1] += arr[i];
                cout << i << " " << i + 1 << endl;
            }
        }
        else {

            cout << 2*n + 3 << endl;

            int maxi = INT_MIN;
            int maxInd = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] > maxi) {
                    maxi = max(arr[i], maxi);
                    maxInd = i;
                }
            }
            
            for (int i = 0; i < 5; i++) {
                arr[maxInd] += arr[maxInd];
                cout << maxInd + 1 << " " << maxInd + 1 << endl;
            }

            for (int i = 0; i < n; i++ ) {
                if (i != maxInd) {
                    arr[i] += arr[maxInd];
                    cout << i + 1 << " " << maxInd + 1 << endl;
                }
            }

            for (int i = 1; i < n; i++) {
                arr[i] += arr[i-1];
                cout << i + 1 << " " << i << endl;
            }
        }
    }

    return 0;
}