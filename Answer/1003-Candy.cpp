/**
 * Author: kutomei3
 * file: see u TOI21
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200001;
const int md = 1e9 + 7;

int fac[MAXN], inv[MAXN];

int exp(int x, int n, int m) {
    int res = 1;
    x %= m;
    while (n > 0) {
        if (n % 2 == 1) res = res * x % m;
        x = x * x % m;
        n /= 2;
    }
    return res;
}

int calnCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fac[n] * inv[r] % md * inv[n - r] % md;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % md;
    }
    inv[MAXN - 1] = exp(fac[MAXN - 1], md - 2, md);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % md;
    }

    vector<vector<int>> pfs(n + 1, vector<int>(21, 0));
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        for (int j = 0; j <= 20; j++) {
            pfs[i][j] = pfs[i - 1][j] + (j == u ? 1 : 0);
        }
    }

    while (q--) {
        int l, r, c;
        cin >> l >> r >> c;
        int cal = calnCr(pfs[r + 1][c] - pfs[l][c], k);
        cout << (cal ? cal : -1) << '\n';
    }

    return 0;
}
