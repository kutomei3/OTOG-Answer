/**
 * Author: kutomei3
 * date: 6-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        int cm = 0, un = 0;
        map<int, bool> mp;
        for (int j = i; j < n; j++) {
            cm = max(vec[j], cm);
            if (!mp[vec[j]]) {
                un++;
                mp[vec[j]] = true;
            }
            arr[i][j] = un * cm;
        }
    }

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = arr[0][i];
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + arr[j + 1][i]);
        }
    }

    cout << dp[n - 1];

    return 0;
}
