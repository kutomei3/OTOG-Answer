/**
 * Author: kutomei3
 * file: see u TOI21
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;
    sort(vec.begin(), vec.end());

    map<int, int> mp;
    vector<int> mpv(n);
    int cd = 0, nd = 0;
    for (int i = 0; i < n; i++) {
        if (mp[vec[i]] == 0) cd++;
        else if (mp[vec[i]] == 1) nd++;
        mp[vec[i]]++;
        mpv[i] = cd * (cd - 1) / 2 + nd;
    } 

    int q;
    cin >> q;
    while (q--) {
        int u;
        cin >> u;
        for (int i = 0; i < 60; i++) {
            auto it = lower_bound(vec.begin(), vec.end(), (1 << i));
            int ps = (it == vec.end() ? n - 1 : it - vec.begin() - 1);
            if (u == mpv[ps]) {
                cout << (1 << i) << '\n';
                break;
            }
            if (ps == n - 1) {
                cout << "-1\n";
                break;
            }
        }
    }

    return 0;
}
