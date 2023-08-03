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
        int k;
        cin >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxi = INT_MIN;
        for (auto it: arr) {
            maxi = max(maxi, it);
        }

        vector<int> temp(maxi+1);
        temp.push_back(0);

        for (int i = 1; i < maxi+1; i++) {
            temp.push_back(i);
        }

        for (int i = 0; i < k; i++) {
            for (auto it: arr) {
                temp[it] = -1;
            }
            vector<int> v(maxi+1);
            v.push_back(0);
            for (auto it: temp) {
                if (it != -1) {
                    v.push_back(it);
                }
            }
            int j = *(v.end()- 1);
        }
    }

    return 0;
}