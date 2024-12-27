#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> all(n + 1);

    int x, y;
    while (m--) {
        cin >> x >> y;
        all[x].push_back(y);
        all[y].push_back(x);
    }

    vector<pair<int, int>> alld(n + 1);
    vector<bool> vis(n + 1, false);

    while (t--)
    {
        int ti;
        cin >> ti;

        queue<pair<int, int>> qu;
        qu.push({ti, 0});

        while (!qu.empty())
        {
            auto qf = qu.front();
            qu.pop();

            vis[qf.first] = true;
            alld[qf.first] = {t, qf.second};

            for (auto& p : all[qf.first])
                if (!vis[p]) qu.push({p, qf.second + 1});
        }
    }

    int q, u, v;
    cin >> q;

    while (q--) {
        cin >> u >> v;
        
        if (alld[u].first == alld[v].first && alld[u].second > alld[v].second)
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
