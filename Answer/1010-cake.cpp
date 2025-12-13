#include <bits/stdc++.h>
using namespace std;

vector<int> vec(100002);

struct DSU {
    vector<int> par;
    vector<set<int>> as;
    DSU(int _n) {
        par.resize(_n);
        iota(par.begin(), par.end(), 0);
        as.assign(_n, set<int>());
        for (int i = 0; i < _n; i++) {
            as[i].insert(vec[i]);
        }
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (as[px].size() < as[py].size()) swap(px, py);
        par[py] = px;
        for (auto& p : as[py]) {
            as[px].insert(p);
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    vector<pair<int, int>> qr(q);
    DSU dsu(n + 1);

    vector<int> ass;
    ass.push_back(-1);
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        qr[i] = {x, y - 1};
        if (x == 1) ass.push_back(y - 1);
    }
    sort(ass.begin(), ass.end());
    ass.push_back(n - 1);

    for (int i = 0; i < ass.size() - 1; i++) {
        for (int j = ass[i] + 1; j <= ass[i + 1]; j++) {
            dsu.join(ass[i] + 1, j);
        }
    }

    vector<int> ans;
    for (int i = q - 1; i >= 0; i--) {
        auto [x, y] = qr[i];
        if (x == 2) ans.push_back(dsu.as[dsu.find(y)].size());
        else dsu.join(y, y + 1);
    }

    for (int i = ans.size() - 1; i >= 0; i--) printf("%d\n", ans[i]);
    
    return 0;
}
