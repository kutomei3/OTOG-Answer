#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n + 2, 0);
    for (int i = 2; i <= n + 1; i++) cin >> vec[i];

    vector<int> dp(n + 2, 0);
    for (int i = 2; i <= n + 1; i++) {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i - 2] + vec[i], dp[i]);
    }

    cout << dp[n + 1];

    return 0;
}
