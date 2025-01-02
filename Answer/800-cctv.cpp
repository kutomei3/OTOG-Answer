#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> all(n);

    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        all[u].push_back({w, v});
        all[v].push_back({w, u});
    }

    vector<bool> vis(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sal;

    priority_queue<int> pq;

    sal.push({0, 0});
    while (!sal.empty())
    {
        auto qf = sal.top();
        sal.pop();

        if (vis[qf.second]) continue;
        vis[qf.second] = true;

        pq.push(qf.first);

        for (auto& p : all[qf.second]) {
            if (!vis[p.second]) {
                sal.push({p.first, p.second});
            }
        }
    }

    while (k--) {
        pq.push(pq.top() / 2);
        pq.pop();   
    }

    int ans = 0;
    while (pq.size())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}
