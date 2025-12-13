#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int arr[n], vec[n];
    for (auto& p : arr) cin >> p;
    for (auto& p : vec) cin >> p;

    int sum = 0;
    for (int i = 0; i < m; i++) sum += arr[i];

    vector<int> suma = {sum};
    for (int i = m; i < n; i++) {
        sum += arr[i] - arr[i - m];
        suma.push_back(sum);
    }

    //for (auto& p : suma) cout << p << ' ';

    sort(suma.begin(), suma.end());

    sum = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) sum += vec[i];
    //cout << sum << ' ';

    ans += n - m + 1 - (lower_bound(suma.begin(), suma.end(), k - sum) - suma.begin());
    for (int i = m; i < n; i++) {
        //cout << i << ' ' << arr[i - m] << '\n';
        sum += vec[i] - vec[i - m];
        //cout << sum << ' ';
        ans += n - m + 1 - (lower_bound(suma.begin(), suma.end(), k - sum) - suma.begin());
    }

    cout << ans;

    return 0;
}
