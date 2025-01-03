#include <bits/stdc++.h>
using namespace std;

#define mod 10000009

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    char maz[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maz[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(401, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maz[i][j] == '#') continue;
            else if (maz[i][j] == 'X') {
                for (int p = 0; p < 400; p++) {
                    dp[i][j][p + 1] += i - 1 < 0 ? 0 : dp[i - 1][j][p];
                    dp[i][j][p + 1] += j - 1 < 0 ? 0 : dp[i][j - 1][p];
                    dp[i][j][p + 1] %= mod;
                }
            }
            else {
                for (int p = 0; p < 400; p++) {
                    dp[i][j][p] += i - 1 < 0 ? 0 : dp[i - 1][j][p];
                    dp[i][j][p] += j - 1 < 0 ? 0 : dp[i][j - 1][p];
                    dp[i][j][p] %= mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= min(400, r); i++) 
        ans += dp[n - 1][m - 1][i];

    cout << ans % mod;

    return 0;
}

//3d vector :P
