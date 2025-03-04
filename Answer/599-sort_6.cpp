#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    for (auto& [u, v] : vec) cin >> u >> v;

    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    for (auto& [u, v] : vec) cout << u << ' ' << v << '\n';

    return 0;
}
