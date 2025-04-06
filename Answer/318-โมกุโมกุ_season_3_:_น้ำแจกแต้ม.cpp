#include <bits/stdc++.h>
using namespace std;

#define int long long

bool can(vector<int> &vec, int m, int p) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i] / m;
    }
    return (sum < p);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    int l = 1;
    int r = INT_MAX;

    while (r > l) {
        int m = (r + l) / 2;
        if (can(vec, m, p)) r = m;
        else l = m + 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += vec[i] / (l - 1);
    cout << (sum == p ? "YES\n" : "NO\n");
    cout << l - 1;

    return 0;
}
