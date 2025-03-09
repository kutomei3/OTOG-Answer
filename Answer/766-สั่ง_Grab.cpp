/**
 *  Author: kutomei3
 *  Task: สั่ง Grab no.766
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void dij(vector<vector<pair<int, int>>> &ap, vector<int> &mn, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({mn[s], s});

    while (pq.size())
    {
        auto [w, n] = pq.top();
        pq.pop();

        for (auto& [d, v] : ap[n]) {
            if (d + w < mn[v]) {
                mn[v] = d + w;
                pq.push({mn[v], v});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<pair<int, int>>> ap(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    vector<vector<int>> mn(n + 1, vector<int>(n + 1, INT_MAX));
    while (k--) {
        int u;
        cin >> u;

        mn[u][u] = 0;
        dij(ap, mn[u], u);
    }

    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;

        cout << mn[v][u] + mn[v][w] << '\n';
    }

    return 0;
}

