#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    vector<long long> dp(56);
    dp[0] = 0; dp[1] = 69;

    for (int i = 2; i <= 55; i++) {
        if (i & 1) dp[i] = dp[i - 1] + dp[i - 2] + i;
        else dp[i] = dp[i - 1] + i;
    }

    int ai;
    while (q--) {
        cin >> ai;
        cout << dp[ai] << '\n';
    }

    return 0;
}
