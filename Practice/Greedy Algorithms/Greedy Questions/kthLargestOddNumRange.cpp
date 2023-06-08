#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int k)
{
    if (k <= 0)
    {
        return 0;
    }

    if ((r & 1) > 0)
    {
        int count = (int)ceil((r - l + 1) / 2);
        if (k > count)
        {
            return 0;
        }
        else
        {
            return (r - 2 * k + 2);
        }
    }
    else
    {
        int count = (r - l + 1) / 2;
        if (k > count)
        {
            return 0;
        }
        else
        {
            return (r - 2 * k + 1);
        }
    }
}

int main()
{
    int l = -10;
    int r = 10;
    int k = 8;

    cout << solve (l, r, k);

    return 0;
}