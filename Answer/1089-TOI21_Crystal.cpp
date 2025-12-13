#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pll pair<int, int>

vector<vector<int>> b(1002);
void upd(int ind, int k, int va) {
    int n = b[k].size() - 1;
    for (ind++; ind <= n; ind += ind & -ind) {
        b[k][ind] = max(b[k][ind], va);
    }
}
int rq(int ind, int k) {
    //int n = b[k].size() + 1;
    int res = 0;
    for (ind++; ind > 0; ind -= ind & -ind) {
        res = max(res, b[k][ind]);
    }
    return res;
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int u, k, n;
    cin >> u >> k >> n;

    vector<array<int, 3>> vec(n);
    vector<int> all[u + 1]; 
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    vector<int> comp1;
    map<int, int> mp;
    for (auto& [a, b, c] : vec) comp1.push_back(a);
    sort(comp1.begin(), comp1.end());
    int t = 0;
    for (auto& a : comp1) {
        if (!mp[a]) mp[a] = t++;
    }
    for (auto& [a, b, c] : vec) a = mp[a];

    sort(vec.begin(), vec.end(), [&](array<int, 3> a, array<int, 3> b) {
        return a[2] < b[2];
    });

    //for (auto& [a, b, c] : vec) cout << a << ' ' << b << ' ' << c << '\n';

    for (auto& [a, b, c] : vec) {
        all[b].push_back(a);
    }
    for (int i = 0; i <= u; i++) {
        sort(all[i].begin(), all[i].end());
        b[i].assign(all[i].size() + 3, 0);
    }
    map<int, pair<int, int>> ind;
    for (int i = 0; i <= u; i++) {
        int ct = 0;
        for (auto& p : all[i]) ind[p].second = ct++; 
    }

    b[1001].assign(n + 4, 0);

    //for (auto& [a, b, c] : vec) cout << a << ' ' << b << ' ' << ind[a].second << '\n';

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int ans = 1 + max(rq(ind[vec[i][0]].second, vec[i][1]), rq(vec[i][0], 1001) - k);
        upd(vec[i][0], 1001, ans); 
        upd(ind[vec[i][0]].second, vec[i][1], ans);
        mx = max(ans, mx);
    }

    cout << mx;

    return 0;
}

/*
dp[n][k] += sum of all i < n -> dp[i][k - 1]
loop n, k




*/
