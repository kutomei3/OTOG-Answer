#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> all(n);
    for (auto& p : all) cin >> p;

    sort(all.begin(), all.end());

    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + all[i - 1];

    int qi;
    while (q--) {
        cin >> qi;
        cout << upper_bound(ps.begin(), ps.end(), qi) - ps.begin() - 1 << '\n';
    }

    return 0;
}
