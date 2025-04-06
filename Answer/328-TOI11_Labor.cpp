#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    int l = 0;
    int r = (int)10e18 * 1ll;

    while (r > l) {
        int mid = (r + l) / 2;
        int ct = 0;
        for (auto& p : vec) ct += mid / p;
        if (ct >= k) r = mid;
        else l = mid + 1;
    }

    cout << l;

    return 0;
}
