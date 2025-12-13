#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    sort(vec.begin(), vec.end());

    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;

        auto it1 = lower_bound(vec.begin(), vec.end(), l - d);
        auto it2 = upper_bound(vec.begin(), vec.end(), r - d);

        cout << max((it2 - it1) * 1ll, 0ll) << '\n';
    }
    
    return 0;
}
