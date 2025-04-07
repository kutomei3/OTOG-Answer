/**
 * Author: kutomei3
 * date: 7-4-2025
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

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        int mx = 0, un = 0;
        map<int, bool> mp;
        for (int j = i; j < n; j++) {
            mx = max(mx, vec[j]);
            if (!mp[vec[j]]) {
                un++;
                mp[vec[j]] = true;
            }
            dp[j + 1] = max(dp[j + 1], dp[i] + un * mx);
        }
    }

    cout << dp[n];

    return 0;
}
