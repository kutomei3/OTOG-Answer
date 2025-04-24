/**
 * Author: kutomei3
 * date: 24-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree {
    int n;
    vector<int> mx, mn;

    segtree(vector<int> &vec) {
        n = vec.size();
        mx.assign(4 * n, LLONG_MIN);
        mn.assign(4 * n, LLONG_MAX);
        build(vec, 0, 0, n - 1);
    }

    void build(vector<int> &vec, int cn, int l, int r) {
        if (l == r) {
            mx[cn] = mn[cn] = vec[l];
        }
        else {
            int mid = (r + l) >> 1;
            int lc = 2 * cn + 1;
            int rc = 2 * cn + 2;
            build(vec, lc, l, mid);
            build(vec, rc, mid + 1, r);
            mn[cn] = min(mn[lc], mn[rc]);
            mx[cn] = max(mx[lc], mx[rc]);
        }
    }

    void update(int cn, int l, int r, int ind, int va) {
        if (l == r) {
            mx[cn] = mn[cn] = va;
        }
        else {
            int mid = (r + l) >> 1;
            int lc = 2 * cn + 1;
            int rc = 2 * cn + 2;
            if (ind <= mid) update(lc, l, mid, ind, va);
            else update(rc, mid + 1, r, ind, va);
            mn[cn] = min(mn[lc], mn[rc]);
            mx[cn] = max(mx[lc], mx[rc]);
        }
    }

    int calmn(int cn, int l, int r, int tl, int tr) {
        if (tr < l || r < tl) return LLONG_MAX;
        if (tl <= l && r <= tr) return mn[cn];
        int mid = (l + r) >> 1;
        return min(calmn(2 * cn + 1, l, mid, tl, tr), calmn(2 * cn + 2, mid + 1, r, tl, tr));
    }

    int calmx(int cn, int l, int r, int tl, int tr) {
        if (tr < l || r < tl) return LLONG_MIN;
        if (tl <= l && r <= tr) return mx[cn];
        int mid = (l + r) >> 1;
        return max(calmx(2 * cn + 1, l, mid, tl, tr), calmx(2 * cn + 2, mid + 1, r, tl, tr));
    }

    void upd(int ind, int va) {
        return update(0, 0, n - 1, ind, va);
    }

    pair<int, int> q(int tl, int tr) {
        return {calmn(0, 0, n - 1, tl, tr), calmx(0, 0, n - 1, tl, tr)};
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    segtree sgt(vec);

    char c;
    int u, v;
    while (cin >> c >> u >> v) {
        if (c == 'U') sgt.upd(u, v);
        else {
            auto [f, s] = sgt.q(u, v);
            cout << f << ' ' << s << '\n';
        }
    }

    return 0;
}
