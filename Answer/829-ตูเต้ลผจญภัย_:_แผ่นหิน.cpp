#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> all(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> all[i];

    vector<int> ans(n);
    for (int i = 1; i < n; i++)
        ans[i] = all[i - 1] + all[i] + all[i + 1];

    int k;
    while (q--) {
        cin >> k;
        cout << lower_bound(ans.begin(), ans.end(), k) - ans.begin() << '\n';
    }

    return 0;
}
