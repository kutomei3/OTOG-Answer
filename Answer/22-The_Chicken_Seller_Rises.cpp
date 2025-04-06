#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    scanf("%lld %lld", &n, &m);

    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int xs, ys, xe, ye;
    scanf("%lld %lld %lld %lld", &xs, &ys, &xe, &ye);
    xs--, ys--, xe--, ye--;

    int di[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dj[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

    queue<pair<int, int>> qu;
    qu.push({xs, ys});

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[xs][ys] = 0;

    while (qu.size())
    {
        auto [u, v] = qu.front();
        qu.pop();

        for (int p = 0; p < 8; p++) {
            int du = u + di[p];
            int dv = v + dj[p];

            if (du < 0 || du >= n || dv < 0 || dv >= m) continue;
            if (arr[du][dv] == 'X' || dp[du][dv] != INT_MAX) continue;

            dp[du][dv] = dp[u][v] + 1;
            qu.push({du, dv});
        }
    }

    printf("%lld", (dp[xe][ye] == INT_MAX ? -1ll : dp[xe][ye]));

    return 0;
}
