#include <bits/stdc++.h>
using namespace std;

vector<int> dij(vector<vector<pair<int, int>>> &way, int n, int pos)
{
    vector<int> mn(n + 1, INT_MAX);
    mn[pos] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, pos});

    vector<bool> vis(n + 1, false);

    while (!pq.empty())
    {
        auto pf = pq.top();
        pq.pop();

        mn[pf.second] = min(mn[pf.second], pf.first);
        vis[pf.second] = true;

        for (auto& p : way[pf.second]) {
            if (vis[p.second]) continue;
            pq.push({p.first + pf.first, p.second});
        }
    }

    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q, s, t;
    cin >> n >> m >> q >> s >> t;

    vector<vector<pair<int, int>>> ways(n + 1);
    vector<vector<pair<int, int>>> waye(n + 1); 

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ways[u].push_back({w, v});
        waye[v].push_back({w, u});
    }

    vector<int> mns = dij(ways, n, s);
    vector<int> mne = dij(waye, n, t);

    int qi;
    while (q--) {
        cin >> qi;
        cout << mns[qi] + mne[qi] << '\n';
    }

    return 0;
}
