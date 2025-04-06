#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<bool, int> can(vector<vector<pair<int, int>>> &ap, vector<int> &sst, int mid, int a, int b, int g)
{
    vector<int> mn(sst.size(), LLONG_MAX);
    mn[a] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, a});

    while (!pq.empty())
    {
        auto [u, v] = pq.top();
        pq.pop();

        for (auto &[w, n] : ap[v]) {
            if (sst[n] <= mid && w + u < mn[n]) {
                mn[n] = w + u;
                pq.push({mn[n], n});
            }
        }
    }

    return {(mn[b] <= g), mn[b]};
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, g;
    char as[102], bs[102];
    scanf("%lld %lld %s %s %lld", &n, &m, as, bs, &g);

    unordered_map<string, int> nm;
    vector<int> sst(n);

    for (int i = 0; i < n; i++) {
        char u[102];
        int v;
        scanf("%s %lld", u, &v);

        nm[u] = i;
        sst[i] = v;
    }

    vector<vector<pair<int, int>>> ap(n);
    for (int i = 0; i < m; i++) {
        char u[102], v[102];
        int w;
        scanf("%s %s %lld", u, v, &w);

        int ui = nm[u];
        int vi = nm[v];

        ap[ui].push_back({w, vi});
        ap[vi].push_back({w, ui});
    }

    int a = nm[as];
    int b = nm[bs];

    int l = 0, r = *max_element(sst.begin(), sst.end()) + 1, av;
    while (r > l) {
        int mid = (r + l) / 2;
        auto [c, o] = can(ap, sst, mid, a, b, g);
        if (c) r = mid, av = o;
        else l = mid + 1;
    }

    printf("%lld %lld\n", l, av);

    return 0;
}
