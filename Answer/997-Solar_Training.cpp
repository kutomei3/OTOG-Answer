#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> ap(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    vector<int> gc(n, -1);
    vector<int> wfeg(n, 0);
    int ct = 0;

    for (int i = 0; i < n; i++) {
        if (gc[i] != -1) continue;
        queue<int> qu;
        qu.push(i);

        ct++;
        int wa = 0;

        while (qu.size())
        {
            auto qf = qu.front();
            qu.pop();

            gc[qf] = ct;

            for (auto& [w, p] : ap[qf]) {
                if (gc[p] == -1) {
                    gc[p] = ct;
                    qu.push(p);
                }
                wa |= (1ll << w);
            }
        }

        wfeg[ct] = wa;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (gc[u] != gc[v]) cout << -1 << '\n';
        else cout << wfeg[gc[u]] << '\n';
    }

    return 0;
}
