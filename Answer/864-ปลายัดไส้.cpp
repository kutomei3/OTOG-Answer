/**
 *  Author: kutomei3
 *  Task: ปลายัดไส้ no.864
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q, x;
    cin >> n >> k >> q >> x;
    
    vector<int> af(n + 1);
    for (int i = 1; i <= n; i++) cin >> af[i];

    vector<vector<pair<int, int>>> ap(n + 1);

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        ap[u].push_back({af[v], v});
    }

    vector<int> mn(n + 1, INT_MAX);
    mn[x] = af[x];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({x, mn[x]});

    while (pq.size())
    {
        auto [u, w] = pq.top();
        pq.pop();

        for (auto& [di, v] : ap[u]) {
            if (di + w < mn[v]) {
                mn[v] = di + w;
                pq.push({v, mn[v]});
            }
        }
    }

    while (q--) {
        int qi;
        cin >> qi;

        cout << mn[qi] << '\n';
    }

    return 0;
}
