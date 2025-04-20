/**
 * Author: kutomei3
 * date: 20-4-2025
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

    int arr[4][n + 1];
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<vector<int>>> dp(4, vector<vector<int>>(4, vector<int>(n + 2, 0)));
    for (int i = n / 2; i >= 1; i--) {
        for (int j = 0; j < 4; j++) {
            for (int p = 0; p < 4; p++) {
                if (j == p) continue;
                int va = dp[j][p][i] + arr[j][i] + arr[p][n - i + 1];
                for (int u = 0; u < 4; u++) {
                    for (int v = 0; v < 4; v++) {
                        if (u == v || j == u || p == v) continue;
                        dp[u][v][i - 1] = max(dp[u][v][i - 1], va);
                    }
                }
            }
        }
    }

    int mx = 0;
    for (int j = 0; j < 4; j++) {
        for (int p = 0; p < 4; p++) {
            mx = max(mx, dp[j][p][0]);
        }
    }

    cout << mx;

    return 0;
}
