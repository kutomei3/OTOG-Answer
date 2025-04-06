#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    vector<int> dp(100001, 0);
    vector<int> c = {1, 5, 10, 25, 50};
    dp[0] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = c[i]; j < 100001; j++) {
            dp[j] += dp[j - c[i]];
            dp[j] %= 1000003;
        }
    }

    while (q--) {
        int qi;
        cin >> qi;
        cout << dp[qi] << '\n';
    }

    return 0;
}
