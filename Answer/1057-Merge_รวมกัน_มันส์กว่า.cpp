/**
 * Author: kutomei3
 * file: see u TOI21
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    int arr[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 3, -1));
    dp[0][1] = 0;

    for (int m = 0; m < k; m++) {
        for (int i = 1; i <= n; i++) {
            if (dp[m][i] == -1) continue;

            dp[m][i + 1] = max(dp[m][i + 1], dp[m][i]);
            for (int j = i; j <= n; j++) {
                dp[m + 1][j + 2] = max(dp[m + 1][j + 2], dp[m][i] + arr[i][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n + 2; i++){
        ans = max(ans, dp[k][i]);
    }
    cout << ans;
    
    return 0;
}
