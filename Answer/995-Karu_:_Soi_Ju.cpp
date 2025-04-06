#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<array<int, 3>>> ap(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[i].push_back({u, i + 1, 0});
        ap[i].push_back({w, v, 1});
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, 0});

    vector<vector<int>> mn(n, vector<int>(k + 1, LLONG_MAX));
    while (pq.size())
    {
        auto [d, c, u] = pq.top();
        pq.pop();

        for (auto& [w, v, s] : ap[u]) {
            if (s == 0) {
                if (mn[v][c] > w + d) {
                    mn[v][c] = w + d;
                    pq.push({mn[v][c], c, v});
                }
            }
            else {
                if (c < k && mn[v][c + 1] > w + d) {
                    mn[v][c + 1] = w + d;
                    pq.push({mn[v][c + 1], c + 1, v});
                }
            }
        }
    }

    cout << *min_element(mn[n - 1].begin(), mn[n - 1].end());

    return 0;
}
