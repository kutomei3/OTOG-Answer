/**
 * Author: kutomei3
 * date: 22-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> an(n + 1, 0);
    for (int i = 0; i < 2 * n - 1; i++) {
        int u;
        cin >> u;
        an[u]++;
    }

    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= (int)1e9 + 7;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= f[an[i] - 1];
        ans %= (int)1e9 + 7;
    }

    cout << ans;

    return 0;
}
