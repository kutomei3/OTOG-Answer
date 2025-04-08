#include <bits/stdc++.h>
using namespace std;

#define int long long
int k;

vector<vector<vector<int>>> dp(10, vector<vector<int>>(301, vector<int>(301, -1)));
int dfs(vector<int> &pfs, int m, int d, int l, int r)
{
    if (m == k) return 1;
    if (dp[m][l][r] != -1) return dp[m][l][r]; 
    
    int mas = 0;
    for (int i = l; i < r; i++) {
        if (abs(pfs[i] - pfs[l - 1] - (pfs[r] - pfs[i])) <= d) {
            mas += dfs(pfs, m + 1, d, i + 1, r) * dfs(pfs, m + 1, d, l, i);
            mas %= 1000000007;
        }
    }
    return dp[m][l][r] = mas;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> k >> d;

    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;

        pfs[i] = pfs[i - 1] + u;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (abs(pfs[i] - pfs[0] - (pfs[n] - pfs[i])) <= d) {
            ans += dfs(pfs, 2, d, i + 1, n) * dfs(pfs, 2, d, 1, i);
            ans %= 1000000007;
        }
    }

    cout << ans;

    return 0;
}
