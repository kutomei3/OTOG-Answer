/**
 * Author: kutomei3
 * date: 16-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;

    int arr[c][n][m];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < m; p++) {
                cin >> arr[i][j][p];
            }
        }
    }

    vector<vector<vector<int>>> dp(c, vector<vector<int>>(n, vector<int>(m, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < m; p++) {
                if (j > 0) dp[i][j][p] = max(dp[i][j][p], dp[i][j - 1][p]);
                if (p > 0) dp[i][j][p] = max(dp[i][j][p], dp[i][j][p - 1]);
                if (i > 0 && arr[i - 1][j][p] < 0) dp[i][j][p] = max(dp[i][j][p], dp[i - 1][j][p]);
                if (dp[i][j][p] == -1) continue;
                dp[i][j][p] += abs(arr[i][j][p]);
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < c; i++) mx = max(mx, dp[i][n - 1][m - 1]);
    cout << mx;

    return 0;
}
