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

    sort(vec.rbegin(), vec.rend());
    
    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + vec[i - 1];

    int qi;
    while (q--) {
        cin >> qi;
        if (lower_bound(ps.begin(), ps.end(), qi) != ps.end()) {
            cout << lower_bound(ps.begin(), ps.end(), qi) - ps.begin() << '\n';
        }
        else cout << "NO" << '\n';
    }

    return 0;
}
