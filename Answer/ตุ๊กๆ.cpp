#include <bits/stdc++.h>
using namespace std;

bool can(vector<vector<pair<int, int>>> &allp, int m, int k)
{
    int n = allp.size();

    vector<bool> vis(n, false);
    int ct = 0;
    
    for (int i = 1; i < n; i++) 
    {
        if (vis[i]) continue;
        ct++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});

        while (pq.size())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            vis[node] = true;

            for (auto& [weg, nei] : allp[node]) 
                if (weg >= m && !vis[nei]) pq.push({weg, nei});
        }
    }

    return ct > k;
}   


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> allp(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        allp[u].push_back({w, v});
        allp[v].push_back({w, u});
    }

    int l = 0;
    int h = 10e9 + 1;

    while (h > l) {
        int mid = (h + l) / 2;
        if (can(allp, mid, k)) h = mid;
        else l = mid + 1;
    }

    cout << l - 1;

    return 0;
}
