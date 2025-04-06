#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    pair<int, int> start, end;
    bool foundStart = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                if (!foundStart) start = {i, j}, foundStart = true;
                else end = {i, j};
            }
        }
    }

    int x1 = start.first, y1 = start.second;
    int x2 = end.first, y2 = end.second;

    vector<vector<int>> dp(n, vector<int>(n, LLONG_MAX));

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({arr[x1][y1], x1, y1});
    dp[x1][y1] = arr[x1][y1];

    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};

    while (!pq.empty()) {
        auto [w, x, y] = pq.top();
        pq.pop();

        if (dp[x][y] < w) continue;

        for (int p = 0; p < 4; p++) {
            int du = x + di[p];
            int dv = y + dj[p];

            if (du < 0 || du >= n || dv < 0 || dv >= n) continue;

            int newW = max(w, arr[du][dv]);
            if (newW < dp[du][dv]) {
                dp[du][dv] = newW;
                pq.push({newW, du, dv});
            }
        }
    }

    cout << dp[x2][y2] << '\n';

    return 0;
}
