/**
 * Author: kutomei3
 * date: 28-4-2025
**/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long

struct Segtree {
    int n;
    vector<int> t;

    Segtree(int _n) : n(_n), t(4 * n, 0) {}

    void update(int cn, int l, int r, int ind, int va) {
        if (l == r) t[cn] = va;
        else {
            int mid = (r + l) >> 1;
            int ln = cn << 1 | 1;
            if (ind <= mid) update(ln, l, mid, ind, va);
            else update(ln + 1, mid + 1, r, ind, va);
            t[cn] = max(t[ln], t[ln + 1]);
        }
    }

    int calq(int cn, int l, int r, int tl, int tr) {
        if (l > tr || r < tl) return 0;
        if (l >= tl && r <= tr) return t[cn];
        int mid = (r + l) >> 1;
        int ln = cn << 1 | 1;
        return max(calq(ln, l, mid, tl, tr), calq(ln + 1, mid + 1, r, tl, tr));
    }

    void upd(int ind, int va) {
        update(0, 0, n - 1, ind - 1, va);
    }

    int ans() {
        return calq(0, 0, n - 1, 0, n - 1);
    }
};
 
signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, p, a, b;
    cin >> n >> m >> p >> a >> b;

    vector<int> ap[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ap[u].push_back(v);
        ap[v].push_back(u);
    }

    vector<int> mta(n + 1, INT_MAX);
    mta[a] = 0;

    queue<int> qu;
    qu.push(a);

    while (qu.size())
    {
        auto qf = qu.front();
        qu.pop();

        for (auto& v : ap[qf]) {
            if (mta[v] > mta[qf] + 1) {
                mta[v] = mta[qf] + 1;
                qu.push(v);
            }
        }
    }

    Segtree sgt(n);
    for (int i = 1; i <= n; i++) {
        sgt.upd(i, mta[i]);
    }

    vector<int> ans(n, INT_MAX);
    vector<bool> vis(n + 1, false);
    vis[b] = true;

    queue<int> cur, net;
    cur.push(b);
    int ctt = 0;
    while (true) {
        if (ctt & 1)
            while (net.size()) {
                auto qf = net.front();
                net.pop();
                
                sgt.upd(qf, 0);
                for (auto& v : ap[qf]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        cur.push(v);
                    }
                }
            }
        else {
            while (cur.size()) {
                auto qf = cur.front();
                cur.pop();

                sgt.upd(qf, 0);
                for (auto& v : ap[qf]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        net.push(v);
                    }
                }
            }
        }

        ans[ctt++] = sgt.ans();
        if (ctt == n) break;
    }

    while (p--) {
        int qi;
        cin >> qi;
        cout << ans[qi] << '\n';
    }
 
    return 0;
}
