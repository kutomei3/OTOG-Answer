#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pll pair<int, int>

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> dp[n + 2];
    dp[0].push_back(0);
    //dp[1].push_back(0);
    for (int i = 0; i <= n + 1; i++) {
        priority_queue<array<int, 3>> pq;
        //cout << '\n' << i << '\n';
        for (int j = 0; j <= i - 2; j++) pq.push({dp[j][0] + arr[j][i - 2], j, 0});
        //for (int j = 0; j <= i - 2; j++) pq.push({arr[0][i - 2]})
        if (i >= 1) pq.push({dp[i - 1][0], i - 1, 0});
        while (pq.size() && dp[i].size() < k) {
            auto [val, at, ind] = pq.top();
            //cout << val << ' ';
            dp[i].push_back(val);
            pq.pop();
            if (at == -1 || ind + 1 == dp[at].size()) continue;
            if (at == i - 1) pq.push({dp[at][ind + 1], at, ind + 1});
            else pq.push({dp[at][ind + 1] + arr[at][i - 2], at, ind + 1});
        }
    }

    // cout << '\n' << '\n';
    // for (int i = 0; i <= n + 1; i++) {
    //     for (auto& p : dp[i]) cout << p << ' ';
    //     cout << '\n';
    // }

    for (auto& p : dp[n + 1]) cout << p << ' ';

    return 0;
}

/*
dp[i][k] += dp[p][k - 1]




*/
