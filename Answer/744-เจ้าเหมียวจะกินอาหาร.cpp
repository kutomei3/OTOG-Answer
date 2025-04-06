#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + vec[i - 1];

    int r = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        while (r < n && pfs[r] - pfs[i] < m) r++;
        if (pfs[r] - pfs[i] >= m) mn = min(mn, r - i);
    }

    cout << mn;

    return 0;
}
