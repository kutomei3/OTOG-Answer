#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    scanf("%lld %lld", &n, &k);

    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &w[i], &v[i]);

    vector<int> dp(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    printf("%lld", dp[k]);

    return 0;
}
