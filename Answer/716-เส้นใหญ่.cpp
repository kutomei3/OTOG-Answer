#include <bits/stdc++.h>
using namespace std;

#define int long long

void bfs(vector<vector<int>> &ap, vector<int> &cl, int s, int ct)
{
    queue<int> qu;
    qu.push(s);

    vector<bool> vis(ap.size(), false);

    while (qu.size())
    {
        auto qf = qu.front();
        qu.pop();

        if (vis[qf]) continue;
        vis[qf] = true;

        cl[qf] = ct;

        for (auto& p : ap[qf]) {
            qu.push(p);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> ap(n + 2);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        ap[u].push_back(v);
        ap[v].push_back(u);
    }

    int ct = 0;
    vector<int> cl(n + 2, -1);
    for (int i = 1; i <= n; i++) {
        if (cl[i] != -1) continue;
        bfs(ap, cl, i, ct++);
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << (cl[u] == cl[v] ? "true\n" : "false\n");
    }

    return 0;
}
