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

    sort(vec.begin(), vec.end(), [](int a, int b) {
        if ((a & 1) == (b & 1)) return a & 1 ? a > b : a < b;
        return (a & 1) < (b & 1);
    });

    for (auto& p : vec) cout << p << ' ';

    return 0;
}
