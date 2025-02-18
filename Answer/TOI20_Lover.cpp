#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, v, w;
    cin >> n >> v >> w;

    vector<int> pfe(n + 1, 0);
    vector<int> pfo(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;

        if (u & 1) pfo[i] += u;
        else pfe[i] += u;

        pfo[i] += pfo[i - 1];
        pfe[i] += pfe[i - 1];
    }

    vector<int> mn(n + 1, INT_MAX);

    queue<pair<int, int>> qu;
    qu.push({0, 0});

    while (qu.size())
    {
        auto [s, k] = qu.front();
        qu.pop();

        if (mn[s] <= k || mn[n] <= k) continue;
        mn[s] = k;

        for (int l = s + 1, r = s + 2; r <= n; r += 2, l += 1) {
            if (pfo[l] - pfo[s] > v) continue;
            if (pfe[r] - pfe[l] > w) continue;
            qu.push({r, k + 1});
        }
    }

    cout << (mn[n] == INT_MAX ? -1 : mn[n]);

    return 0;
}
