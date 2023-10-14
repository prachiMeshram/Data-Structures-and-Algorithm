#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define endl "\n"
#define test ll t; cin>>t; while (t--)

typedef long long int ll;
bool check(vector<pair<ll, ll>> &vp, ll n, ll quan) {
    ll ok = true;
    ll ans = vp[0].first*quan;
    for (ll i = 0; i < n; i++) {
        if (i > 0) {
            ans += (vp[i].first - vp[i-1].first)*quan;
        }
        if (ans < vp[i].second) {
            ok = false;
        }
        ans -= vp[i-1].second ;
    }
    return ok;
}

int main () {
    FI0;
    test{
        ll n, l, r, w;
        cin >> n;
        vector<pair<ll, ll>> vp;
        for (int i = 0; i < n; i++) {
            cin >> l >> r >> w;
            vp.push_back({r, w});
        }
        sort(vp.begin(), vp.end());
        
        ll st = 0, dr = 1e18, ans, mid;

        while (st <= dr) {
            mid = st + (dr-st)/2;

            if (check(vp, n, mid)) {
                ans = mid;
                dr = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
