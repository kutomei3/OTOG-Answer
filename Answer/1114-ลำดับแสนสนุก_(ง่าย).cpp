#include <bits/stdc++.h>
using namespace std;

#define int long long
int md = 998244353ll;

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> dp(n * n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        int ct = (i * (i + 1)) >> 1;
        int cs = 0;
        for (int j = ct - i; j <= ct; j++) cs = (cs + dp[j] + md) % md;
        for (int j = ct; j > i; j--) {
            cs = (cs - dp[j] + md) % md;
            dp[j] = (dp[j] + cs + md) % md;
            cs = (cs + dp[j - i - 1] + md) % md;
        }
        for (int j = i; j >= 0; j--) {
            cs = (cs - dp[j] + md) % md;
            dp[j] = (dp[j] + cs + md) % md;
        }
        // for (int j = 0; j < ct; j++) dp[j] %= md; 
        // for (int j = 0; j < 6; j++) cout << dp[j] << ' ';
        // cout << '\n';
    }

    cout << dp[k] % md;

    return 0;
}

/*
1 2 2
*/
