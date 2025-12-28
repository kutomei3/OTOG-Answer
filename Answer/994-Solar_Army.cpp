#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    vector<int> wn(1000001, 0);
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        wn[u]++;
    }

    vector<int> wh(1000001, 0);

    deque<int> dq;
    int cn = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cn += (wh[vec[i]]++ < wn[vec[i]]);
    }

    if (cn >= k) ans++;

    for (int i = m; i < n; i++) {
        cn += (wh[vec[i]]++ < wn[vec[i]]);
        cn -= (wh[vec[i - m]]-- <= wn[vec[i - m]]);
        if (cn >= k) ans++;
    }

    cout << ans;

    return 0;
}
