#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d1, d2, q, qi;

    cin >> n;

    vector<int> prefix_sum(n + 1);
    prefix_sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> d1 >> d2;
        prefix_sum[i] = prefix_sum[i - 1] + d1 + d2;
    }

    cin >> q;

    while (q--) {
        cin >> qi;

        int ans = upper_bound(prefix_sum.begin(), prefix_sum.end(), qi) - prefix_sum.begin() - 1;
        cout << ans << '\n';
    }

    return 0;
}
