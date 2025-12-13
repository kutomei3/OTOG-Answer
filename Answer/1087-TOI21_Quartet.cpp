#include <bits/stdc++.h>
using namespace std;
 
#define int long long

int n, m;
int t = 0;
void ett(vector<int> &pa, vector<int> &ct, vector<int> ap[], int c, int par) {
    int tf = t;
    pa[c] = par;
    for (auto& p : ap[c]) {
        if (par == p) continue;
        if (p <= n) t++;
        ett(pa, ct, ap, p, c);
    }
    ct[c] = t - tf;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<int> ap[n + m + 1];
    for (int i = 0; i < n + m - 1; i++) {
        int u, v;
        cin >> u >> v;
        ap[u].push_back(v);
        ap[v].push_back(u);
    }

    vector<int> ct(n + m + 1), pa(n + m + 1);
    ett(pa, ct, ap, n + 1, -1);
    for (int i = 1; i <= n; i++) ct[i] = 1;

    int ans = 0;
    for (int i = n + 1; i <= n + m; i++) {
        vector<int> ac;
        for (auto& j : ap[i]) {
            ac.push_back((pa[i] == j ? n - ct[i] : ct[j]));
        }
        int si = ac.size();
        vector<int> dp(5, 0);
        dp[0] = 1;
        for (int j = 0; j < si; j++) {
            for (int p = 4; p >= 1; p--) {
                dp[p] += dp[p - 1] * ac[j];
                dp[p] %= 1000000007;
            }
        }
        ans += dp[4] % 1000000007;
    }

    cout << ans % 1000000007; //why wrong ans :( 
 
    return 0;
}

/*

*/
