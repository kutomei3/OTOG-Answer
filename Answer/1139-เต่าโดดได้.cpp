/**
 * Author: Ohmusan
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int pfs[n + 1];
    pfs[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pfs[i];
        pfs[i] += pfs[i - 1];
    }

    vector<int> cur(n + 2, -1), net(n + 2, -1);
    cur[1] = 0;
    int mx = 0;
    for (int j = 1; j < 449; j++) {
        net.assign(n + 2, -1);
        for (int i = 1; i <= n; i++) {
            if (cur[i] == -1) continue;
            cur[i + 1] = max(cur[i + 1], cur[i]);
            int d = min(n + 1, i + j);
            net[d] = max(net[d], cur[i] + pfs[d - 1] - pfs[i - 1]);
        }
        mx = max(mx, cur[n + 1]);
        cur = net;
    }

    cout << mx;

    return 0;
}
