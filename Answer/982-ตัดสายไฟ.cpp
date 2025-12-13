#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> par(200005);
int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}
void join(int x, int y) {
    int px = find(x);
    int py = find(y);
    par[py] = px;
}

int aw = 0, cl = LLONG_MAX, ind1, ind2;
int dfs(vector<pair<int, int>> ap[], int c, int par, int w) {
    int ay = -w;
    for (auto& [p, d] : ap[c]) {
        //cout << "HERE";
        if (par == p) continue;
        //cout << "HERE";
        int cp = dfs(ap, p, c, d);
        //cout << cp << '\n';
        ay += cp;
        if (cl > abs(aw - 2 * cp - d)) {
            cl = abs(aw - 2 * cp - d);
            ind1 = aw - cp;
            ind2 = cp + d;
        }
    }
    return ay;
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    priority_queue<array<int, 3>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({-w, u, v});
    }

    iota(par.begin(), par.end(), 0);

    vector<pair<int, int>> tap[n + 1];

    int ct = 0;
    while (pq.size()) {
        auto [w, u, v] = pq.top();
        pq.pop();

        if (find(u) != find(v)) {
            ct++;
            join(u, v);
            //cout << u << ' ' << v << '\n';
            tap[u].push_back({v, w});   
            tap[v].push_back({u, w});
            aw -= w;
            if (ct == n - 1) break;
        }
    }

    dfs(tap, 0, -1, 0);
    cout << aw << '\n' << min(ind1, ind2) << ' ' << max(ind1, ind2);   

    return 0;
}
