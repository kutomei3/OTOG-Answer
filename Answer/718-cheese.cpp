/**
 *  Author: kutomei3
 *  Task: cheese no.718
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, g;
    cin >> n >> g;

    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> vec[i];

    vector<vector<int>> dp(n + 1, vector<int>(g + 1, 0));
    for (int i = 0; i <= g; i++) dp[1][i] = vec[1];

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < g + 1; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 2][j] + vec[i]);
            if (j < g) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + vec[i]);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end());

    return 0;
}
