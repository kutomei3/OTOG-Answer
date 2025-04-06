#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> pa(500001, 0);

int fp(int u) {
    if (pa[u] == u) return u;
    return pa[u] = fp(pa[u]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) pa[i] = i;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v>> w;

        pq.push({w, u, v});
    }

    int cost = 0, ct = 0;
    while (pq.size())
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        if (fp(u) != fp(v)) {
            pa[fp(u)] = fp(v);
            cost += w;
            if (++ct == n - 1) break;
        }
    }

    cout << cost;

    return 0;
}
