#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto& p : a) cin >> p;
    for (auto& p : b) cin >> p;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - b[i]);
    }

    cout << sum;

    return 0;
}
