#include<bits/stdc++.h>
using namespace std;

vector<int> dij(vector<vector<pair<int, int>>> &all_path, int p, int n)
{
    vector<int> mn(n + 1, INT_MAX);
    mn[p] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, p});

    while (!pq.empty()) 
    {
        auto [dist, node] = pq.top();
        pq.pop();

        for (auto& [weg, nei] : all_path[node]) 
        {
            if (mn[nei] > weg + dist) {
                mn[nei] = weg + dist;
                pq.push({mn[nei], nei});
            }
        }
    }

    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q, k, p, s;
    cin >> n >> m >> q >> k >> p >> s;
    
    vector<vector<pair<int, int>>> all(n + 1);
    
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        all[u].push_back({w, v});
    }
    
    vector<int> spos = dij(all, s, n);
    vector<int> ppos = dij(all, p, n);
    
    int qi;
    while (q--)
    {
        cin >> qi;
        int mn = min(spos[qi], spos[p] <= k ? ppos[qi] : INT_MAX);
        cout << max(k - mn, -1) << '\n';
    }
    
    return 0;
}
