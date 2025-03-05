/**
 *  Author: kutomei3
 *  Task: shortest_path no.667
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

    vector<int> mn(n, INT_MAX);
    mn[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        for (auto& [d, v] : ap[u]) {
            if (w + d < mn[v]) {
                mn[v] = w + d;
                pq.push({mn[v], v});
            }
        }
    }

    cout << mn[t];

    return 0;
}
