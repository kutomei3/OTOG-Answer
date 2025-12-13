#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
void dfs(vector<int> &vec, vector<int> ap[], int c, int par) {
    for (auto& p : ap[c]) {
        if (p != par) {
            ans += vec[c];
            dfs(vec, ap, p, c);
        }
    }
}

vector<int> par(200005), siz(100002, 1);
int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}
void join(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    if (siz[px] < siz[py]) swap(px, py);
    siz[px] += siz[py];
    par[py] = px;
}

priority_queue<array<int, 3>> pq;
void fuckingcont(int n, vector<int> &vec, vector<int> nap[], vector<int> ap[]) {
    vector<pair<int, int>> vecs;
    while (pq.size()) {
        auto [val, u, v] = pq.top();
        pq.pop();
        if (find(u) != find(v)) {
            join(u, v);
            nap[u].push_back(v);
            nap[v].push_back(u);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n + 1);
    int mx = 0, mxn;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        cin >> vec[i];
        if (vec[i] > mx) {
            mx = vec[i];
            mxn = i;
        }
    }

    vector<int> ap[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        pq.push({-vec[u] - vec[v], u, v});
    }

    vector<int> nap[n + 1];
    fuckingcont(n, vec, nap, ap);

    // for (int i = 1; i <= n; i++) {
    //     for (auto& p : nap[i]) cout << i << ' ' << p << '\n';
    //     cout << '\n';
    // }

    dfs(vec, nap, mxn, -1);

    cout << ans;

    return 0;
}

/*
4 6
1 2 3 4
1 2
1 3
1 4
2 3
2 4
3 4

*/
