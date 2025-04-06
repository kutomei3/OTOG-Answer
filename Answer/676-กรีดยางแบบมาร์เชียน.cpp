#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> vec(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> vec[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if (j < 2) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
            dp[i][j] += vec[i][j];
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end());

    return 0;
}
