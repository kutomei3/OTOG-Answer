#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    vector<pair<int, int>> ap[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        ap[u].push_back({w, v});
        ap[v].push_back({w, u});
    }

    vector<int> mx(n + 1, LLONG_MIN);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
        int u, st;
        scanf("%lld %lld", &u, &st);
        pq.push({st, u});
        mx[u] = st;
    }

    while (pq.size()) {
        auto [st, u] = pq.top();
        pq.pop();

        for (auto& [w, v] : ap[u]) {
            if (mx[v] < st - w) {
                mx[v] = st - w;
                pq.push({mx[v], v});
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (mx[i] >= 0) ans.push_back(i);
    }

    printf("%lld\n", (long long)ans.size());
    for (int p : ans) printf("%lld ", p);

    return 0;
}
