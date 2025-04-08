/**
 * Author: kutomei3
 * date: 9-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> pfs[i];
        pfs[i] += pfs[i - 1];
    }

    vector<int> dp(n + 5, LLONG_MIN);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == LLONG_MIN) continue;
        for (int j = i; j <= min(i + 2, n); j++) {
            for (int p = 2; p <= 4; p++) {
                dp[j + p] = max(dp[j + p], dp[i] + pfs[j] - pfs[i - 1]);
            }
        }
    }

    cout << dp[n + 4];

    return 0;
}
