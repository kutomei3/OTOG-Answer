#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p, k;
    cin >> n >> m >> p >> k;

    vector<vector<pair<int, int>>> ap(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    vector<bool> ah(n + 1, false);
    for (int i = 0; i < p; i++) {
        int u;
        cin >> u;

        ah[u] = true;
    }

    int s;
    cin >> s;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, s});

    vector<vector<int>> mn(n + 1, vector<int>(k + 1, LLONG_MAX));
    mn[s][0] = 0;

    while (pq.size())
    {
        auto [d, c, u] = pq.top();
        pq.pop();

        for (auto& [w, v] : ap[u]) {
            if (ah[v] && c < k && mn[v][c + 1] > w + d) {
                mn[v][c + 1] = w + d;
                pq.push({mn[v][c + 1], c + 1, v});
            }
            else {
                if (mn[v][c] > w + d) {
                    mn[v][c] = w + d;
                    pq.push({mn[v][c], c, v});
                }
            }
        }
    }
    if (mn[s][k] == LLONG_MAX) {
        cout << "NO FOOD :(";
    }
    else cout <<  mn[s][k];
    return 0;
}
