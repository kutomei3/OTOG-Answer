#include <bits/stdc++.h>
using namespace std;

#define int long long
//fix int limit

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, u, l, r;

    cin >> n >> q;

    vector<int> ps(n + 1);
    ps[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> u;
        ps[i] = (i & 1 ? ps[i - 1] + u : ps[i - 1] - u);
    }

    while (q--) {
        cin >> l >> r;
        cout << (l & 1 ? ps[r] - ps[--l] : ps[--l] - ps[r]) << '\n';
    }

    return 0;
}
