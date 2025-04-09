/**
 * Author: kutomei3
 * date: 10-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> pa(100001);
int fi(int x) {
    if (pa[x] == x) return x;
    return pa[x] = fi(pa[x]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) pa[i] = i;

    priority_queue<array<int, 3>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({w, u, v});
    }

    priority_queue<int, vector<int>, greater<int>> wu;
    int va = 0;
    while (pq.size())
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        if (fi(u) != fi(v)) {
            pa[fi(u)] = fi(v);
            wu.push(w);
            va++;
            if (va == n - 1) break;
        }
    }

    for (int i = 1; i <= n; i++) if (pa[i] == i) k--;  
    while (k--) wu.pop();

    cout << wu.top();

    return 0;
}
