/**
 *  Author: kutomei3
 *  Task: เราจะไปทางไหนกันดี no.860
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

    vector<vector<vector<int>>> ap(n + 1, vector<vector<int>>(26));
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;

        ap[u][c - 'a'].push_back(v);
    }

    string s;
    int x, l;
    cin >> x >> l >> s;

    vector<vector<int>> dp(l + 1, vector<int>(n + 1, 0));
    dp[0][x]++;
    for (int i = 0; i < l; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto& p : ap[j][s[i] - 'a']) {
                dp[i + 1][p] += dp[i][j];
                dp[i + 1][p] %= 1000000007;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) sum += dp[l][i];

    cout << sum % 1000000007;

    return 0;
}

