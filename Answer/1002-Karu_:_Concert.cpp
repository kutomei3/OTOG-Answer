/**
 * Author: kutomei3
 * date: 16-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> vis(100001, false);
vector<int> dis(100001, -1), low(100001, -1);
int t = 0;

void dfs(set<pair<int, int>> &bi, vector<pair<int, int>> adj[], int v, int par) {
    vis[v] = true;
    dis[v] = low[v] = t++;
    for (auto& [w, p] : adj[v]) {
        if (p == par) continue;
        if (vis[p]) low[v] = min(low[v], dis[p]);
        else {
            dfs(bi, adj, p, v);
            low[v] = min(low[v], low[p]);
            if (low[p] > dis[v]) {
                bi.insert({min(p, v), max(p, v)});
            }
        }
    }
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    set<pair<int, int>> bi;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(bi, adj, i, -1);
    }

    vector<vector<pair<int, int>>> pa(n);
    for (int u = 0; u < n; u++) {
        for (auto& [w, v] : adj[u]) {
            if (!bi.count({min(u, v), max(u, v)})) {
                pa[u].push_back({w, v});
                pa[v].push_back({w, u});
            }
        }
    }

    while (q--) {
        int ua, va;
        cin >> ua >> va;

        vector<int> mn(n, LLONG_MAX);
        mn[ua] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({mn[ua], ua});

        while (pq.size())
        {
            auto [w, u] = pq.top();
            pq.pop();

            for (auto& [d, v] : pa[u]) {
                if (mn[v] > d + w) {
                    mn[v] = d + w;
                    pq.push({mn[v], v});
                }
            }
        }

        cout << (mn[va] == LLONG_MAX ? -1 : mn[va]) << '\n';
    }

    return 0;
}
