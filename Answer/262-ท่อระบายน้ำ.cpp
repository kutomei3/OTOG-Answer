#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    queue<array<int, 4>> qu;
    qu.push({0, 0, 0, 0});

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    while (qu.size())
    {
        auto [u, v, t, lp] = qu.front();
        qu.pop();

        if (u < 0 || u >= n || v < 0 || v >= m) continue;

        if (vis[u][v]) {
            cout << t + 1 << '\n' << u + 1 << ' ' << v + 1;
            return 0;
        }
        vis[u][v] = true;

        if (arr[u][v] == 'B') {
            if (lp != 4) qu.push({u, v + 1, t + 1, 2});
            if (lp != 3) qu.push({u + 1, v, t + 1, 1});
        }
        else if (arr[u][v] == 'R' && lp != 4) {
            qu.push({u, v + 1, t + 1, 2});
        }
        else if (arr[u][v] == 'D' && lp != 3) {
            qu.push({u + 1, v, t + 1, 1});
        }

        if (u > 0 && lp != 1) {
            if (arr[u - 1][v] == 'B' || arr[u - 1][v] == 'D') qu.push({u - 1, v, t + 1, 3});
        }
        if (v > 0 && lp != 2) {
            if (arr[u][v - 1] == 'R' || arr[u][v - 1] == 'B') qu.push({u, v - 1, t + 1, 4});
        }
    }
    
    return 0;
}
