#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> pa(3001);
int fp(int x) {
    if (pa[x] == x) return x;
    return pa[x] = fp(pa[x]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    scanf("%lld %lld", &n, &m);

    for (int i = 0; i < n; i++) pa[i] = i;

    vector<array<int, 4>> ap;
    for (int i = 0; i < m; i++) {
        int u, v, w, s;
        scanf("%lld %lld %lld %lld", &u, &v, &w, &s);
        ap.push_back({u, v, w, s});
    }

    vector<int> al(1000002, 1e18);

    int q;
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        int l, v;
        scanf("%lld %lld", &l, &v);
        al[l] = min(al[l], v);
    }
    for (int i = 1000000; i >= 0; i--) al[i] = min(al[i + 1], al[i]);

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<bool> vis(n, false);
    int a = 0;
    for (auto& [u, v, w, s] : ap) {
        pq.push({(s == 1 ? 0 : al[w]), u, v});
    }

    int cos = 0;
    while (pq.size())
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        if (fp(u) != fp(v)) {
            pa[fp(u)] = fp(v);
            a++;
            cos += w;
            if (a == n - 1) break;
        }
    }

    printf("%lld", cos);

    return 0;
}
