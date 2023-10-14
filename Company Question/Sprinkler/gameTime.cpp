#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e6 + 1;
void solve()
{

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[1];

    int i = 0;
    vector<int> vl;

    int l = 0;

    int ans = 0;
    while (i < n)
    {

        if (i >= k)
            l -= vl[1 - k];

        if (v[i] < l)
            cout << "-1" << endl;
        return;

        vl.push_back(v[1] - 1);
        l += v[i] - l;

        if (i == (n - 1) && l != v[i])
        {
            cout << "-1" << endl;
            return;
        }

        i++;
    }
    for (auto x : vl)
    {

        ans += x;
    }
    cout << ans << endl;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    cin >> t;

    while (t--)
    {

        solve();
    }
}