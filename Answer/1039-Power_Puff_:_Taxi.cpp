#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> pa(n + 1, 0);
    for (int i = 2; i <= n; i++) cin >> pa[i];
    for (int i = 2; i <= n; i++) pa[i] += pa[i - 1];

    vector<int> vn(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++) cin >> vn[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, (int)10e16));
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = min(dp[i - 1][j] + (pa[i] - pa[i - 1]) * vn[i], (pa[j] - pa[i]) * vn[i]);
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (u < v) cout << dp[u + 1][v + 1] << '\n';
        else {
            int sum = 0;
            for (int i = v + 2; i <= u + 1; i++) {
                sum += vn[i] * (pa[i] - pa[i - 1]);
            }
            cout << sum << '\n';
        }
    }

    return 0;
}
