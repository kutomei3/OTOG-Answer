#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> ap(n);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    int k;
    cin >> k;

    vector<pair<int, int>> port(k);
    for (auto& [u, w] : port) cin >> u >> w;

    vector<int> mn(n, LLONG_MAX);
    mn[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (pq.size())
    {
        auto [w, nd] = pq.top();
        pq.pop();

        for (auto& [wg, d] : ap[nd]) 
        {
            if (wg + w < mn[d]) {
                mn[d] = wg + w;
                pq.push({mn[d], d});
            }
        }
    }

    int ans = LLONG_MAX;
    for (auto& [u, w] : port) 
        ans = min(ans, (u == 0 ? w : (mn[u] == LLONG_MAX ? LLONG_MAX : mn[u] + w)));

    cout << ans;

    return 0;
}
