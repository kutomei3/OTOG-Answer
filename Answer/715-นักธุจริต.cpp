#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t, a, b;
    cin >> n >> m >> t >> a >> b;

    vector<vector<pair<int, int>>> ap(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, a});

    vector<vector<int>> mn(n + 1, vector<int>(t + 1, INT_MAX));

    while (pq.size())
    {
        auto [w, k, u] = pq.top();
        pq.pop();

        for (auto& [d, v] : ap[u]) {
            if (k != t) {
                if (mn[v][k + 1] > d + w) {
                    mn[v][k + 1] = d + w;
                    pq.push({mn[v][k + 1], k + 1, v});
                }
            }
            else {
                if (mn[v][1] > d + w) {
                    mn[v][1] = d + w;
                    pq.push({mn[v][1], 1, v});
                }
            }
        }
    }

    cout << (mn[b][1] == INT_MAX ? -1 : mn[b][1]);

	return 0;
}
