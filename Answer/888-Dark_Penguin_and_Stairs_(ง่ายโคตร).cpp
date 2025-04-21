/**
 * Author: kutomei3
 * date: 21-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

int countWays(int n, int m, vector<int> s)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[j] <= i) dp[i] += dp[i - s[j]]; 
            dp[i] %= (int)1e9 + 7;
        }
    }
    return dp[n];
}
