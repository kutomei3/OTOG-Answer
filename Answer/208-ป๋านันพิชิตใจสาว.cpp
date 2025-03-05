/**
 *  Author: kutomei3
 *  Task: ป๋านันพิชิตใจสาว no.208
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

    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;

        pfs[i] += u + pfs[i - 1];
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << pfs[v] - pfs[u - 1] << '\n';
    }

    return 0;
}

