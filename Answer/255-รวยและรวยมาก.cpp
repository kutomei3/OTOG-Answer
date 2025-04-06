#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> ap(n + 1);
    vector<bool> tn(n + 1, true);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        ap[b].push_back(a);
        tn[a] = false;
    }

    vector<int> vn(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        vn[x] += y;
    }

    vector<int> ans(n + 1, 0);

    queue<pair<int, int>> qu;
    qu.push({1, vn[1]});

    while (qu.size())
    {
        auto [u, w] = qu.front();
        qu.pop();

        ans[u] += w;
        for (auto& p : ap[u]) {
            qu.push({p, w + vn[p]});
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}
