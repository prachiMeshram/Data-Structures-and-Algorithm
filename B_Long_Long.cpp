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

bool allPos(vector<int> &arr) {
    for (auto it: arr) {
        if (it < 0) {
            return false;
        }
    }
    return true;
}

int getSum(vector<int> arr) {
    int sum = 0;
    for (auto it: arr) {
        sum += abs(it);
    }
    return sum;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        int sum = getSum(arr);

        int ops = 0;
        while (!allPos(arr)) {
            int l = 0;

            for (int k = 0; k < n; k++) {
                if (arr[k] <= 0) {
                    l = k;
                    break;
                }
            }
            int r = l;
            while (r < n && arr[r] <= 0) {
                arr[r] = -1* arr[r];
                r++;
            }
            ops++;
        }

        cout << sum << " " << ops << endl;
    }

    return 0;
}