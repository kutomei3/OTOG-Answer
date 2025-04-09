/**
 * Author: kutomei3
 * date: 10-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    s--;

    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[s][0] = arr[s][0];
    for (int j = 0; j < m - 1; j++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][j] == INT_MAX) continue;
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + arr[i][j + 1]);
            if (i > 0) dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + arr[i - 1][j + 1]);
            if (i < n - 1) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
        }
    }

    int mn = INT_MAX;
    vector<int> pa;
    for (int i = 0; i < n; i++) mn = min(mn, dp[i][m - 1]); 
    for (int i = 0; i < n; i++) {
        if (dp[i][m - 1] == mn) {
            int pi = i, pj = m - 1;
            while (pj != 0) {
                int va = dp[pi][pj] - arr[pi][pj];
                pa.push_back(arr[pi][pj]);
                if (va == dp[pi][pj - 1]) pj--;
                else if (pi > 0 && va == dp[pi - 1][pj - 1]) pj--, pi--;
                else if (pi < n - 1 && va == dp[pi + 1][pj - 1]) pj--, pi++;
            }
            break;
        }
    }

    cout << mn << '\n' << arr[s][0] << ' ';
    for (int i = pa.size() - 1; i >= 0; i--) cout << pa[i] << ' ';

    return 0;
}
