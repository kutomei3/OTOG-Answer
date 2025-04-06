#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    scanf("%lld %lld", &n, &m);

    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%lld", &u);

        pfs[i] = pfs[i - 1] + u;
    }

    for (int i = n - 1; i >= 0; i--)
        pfs[i] = min(pfs[i + 1], pfs[i]);

    while (m--) {
        int q;
         scanf("%lld", &q);

        auto it = upper_bound(pfs.begin(), pfs.end(), q);
        if (it != pfs.end()) printf("%lld\n", (it - pfs.begin()) - 1);
        else printf("%lld\n", n);
    }

    return 0;
}
