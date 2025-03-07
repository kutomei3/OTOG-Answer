/**
 *  Author: kutomei3
 *  Task: ฝาแฝด no.861
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> pa(n + 1, 0), pb(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> pa[i];
    for (int i = 1; i <= n; i++) cin >> pb[i];

    for (int i = 1; i <= n; i++) {
        pa[i] += pa[i - 1];
        pb[i] += pb[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        pa[i] = max(pa[i], pa[i - 1]);
        pb[i] = max(pb[i], pb[i - 1]);
    }

    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++) ans[i] = pa[i] + pb[i];

    while (q--) {
        int m;
        cin >> m;

        auto it = lower_bound(ans.begin(), ans.end(), m);
        cout << (it == ans.end() ? n : it - ans.begin()) << '\n';
    }

    return 0;
}
