#include <bits/stdc++.h>
using namespace std;

#define int long long

void dij(vector<int> &mn, vector<vector<pair<int, int>>> &ap, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        for (auto& [d, v] : ap[u]) {
            if (mn[v] > w + d) {
                mn[v] = w + d;
                pq.push({mn[v], v});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    int s, e;
    cin >> s >> e;

    vector<array<int, 3>> api(m);
    vector<vector<pair<int, int>>> ap(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        api[i] = {u, v, w};
        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    vector<int> ss(n, LLONG_MAX), se(n, LLONG_MAX);
    ss[s] = se[e] = 0;
    dij(ss, ap, s);
    dij(se, ap, e);

    while (q--) {
        int i;
        cin >> i;
        auto [fn, sn, w] = api[i];
        int fc = ss[fn] + w + se[sn];
        int sc = ss[sn] + w + se[fn];
        int tc = ss[sn] + w * 2 + se[sn];
        int qc = ss[fn] + w * 2 + se[fn];
        cout << min({fc, sc, tc, qc}) << '\n';
    }

    return 0;
}
