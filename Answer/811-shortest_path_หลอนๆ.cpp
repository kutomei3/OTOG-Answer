/**
 *  Author: kutomei3
 *  Task: shortest_path หลอนๆ no.811
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> ap(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    vector<pair<int, int>> mn(n, {INT_MAX, n});
    mn[s] = {0, s};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        for (auto& [d, v] : ap[u]) {
            if (w + d < mn[v].first) {
                mn[v] = {w + d, u};
                pq.push({mn[v].first, v});
            }
        }
    }
    
    vector<int> p = {t};
    int c = t;
    while (c != s) {
        c = mn[c].second;
        p.push_back(c);
    }

    cout << mn[t].first << '\n' << p.size() << '\n';
    for (int i = p.size() - 1; i >= 0; i--) cout << p[i] << ' ';

    return 0;
}
