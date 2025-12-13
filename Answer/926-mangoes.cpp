#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<array<int, 3>> vec(n);
    for (auto& [u, v, w] : vec) cin >> u >> v >> w;

    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dp[u][v]++;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int lo = 0;
    int hi = max(r, c);

    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        bool ca = true;
        for (int i = 0; i < n; i++) {
            int x = vec[i][0], y = vec[i][1], w = vec[i][2];
            
            int ct  = dp[min(x + mid, r)][min(y + mid, c)] 
                    - dp[max(x - mid - 1, 0ll)][min(y + mid, c)]
                    - dp[min(x + mid, r)][max(y - mid - 1, 0ll)]
                    + dp[max(x - mid - 1, 0ll)][max(y - mid - 1, 0ll)];

            if (ct < w) {
                ca = false;
                break;
            }
        }
        if (ca) hi = mid;
        else lo = mid + 1;
    }

    cout << lo;
 
    return 0;
}
