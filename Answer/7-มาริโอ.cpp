/**
 *  Author: kutomei3
 *  Task: มาริโอ no.7
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < m; i++) dp[0][i] = arr[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            if (j < m - 1) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
            dp[i][j] += arr[i][j];
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());

    return 0;
}
