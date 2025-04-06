#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> p;
void dfs(vector<vector<pair<int, int>>> &ap, vector<bool> &vis, int cur)
{
    if (vis[cur]) return;
    vis[cur] = true;

    for (auto& [w, v] : ap[cur]) {
        if (!vis[v]) {
            dfs(ap, vis, v);
            p.push_back(w);
        }
    }
}

bool can(vector<vector<pair<int, int>>> &ap, int mid)
{
    int sum = 0, ct = 0;
    for (int i = 0; i < p.size(); i++) {
        sum += p[i];
        if (sum >= mid) sum = 0, ct++;
    }

    return (ct < 3);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dg(n + 1);
    vector<vector<pair<int, int>>> ap(n + 1);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        ap[v].push_back({w, u});
        ap[u].push_back({w, v});
        dg[u]++;
        dg[v]++;
    }

    int cur;
    for (int i = 0; i <= n; i++) {
        if (dg[i] == 1) {
            cur = i;
            break;
        }
    }

    vector<bool> vis(ap.size(), false);
    dfs(ap, vis, cur);

    int l = 0;
    int r = INT_MAX;

    while (r > l) {
        int mid = (r + l) / 2;
        if (can(ap, mid)) r = mid;
        else l = mid + 1;
    }

    cout << l - 1;

    return 0;
}
