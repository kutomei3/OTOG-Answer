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

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j - i >= 0) {
                dp[j] += dp[j - i];
            }
        }
    }

    cout << dp[n];

    return 0;
}
