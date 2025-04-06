/**
 * Author: kutomei3
 * date: 7-4-2025
**/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long

#define up {-1, 0}
#define down {1, 0}
#define left {0, -1}
#define right {0, 1}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;

    map<char, vector<pair<int, int>>> dr;
    dr['0'] = {{0, 0}};
    dr['1'] = {up};
    dr['2'] = {right};
    dr['3'] = {down};
    dr['4'] = {left};
    dr['5'] = {up, right};
    dr['6'] = {up, down};
    dr['7'] = {up, left};
    dr['8'] = {down, right};
    dr['9'] = {right, left};
    dr['A'] = {down, left};
    dr['B'] = {right, left, down};
    dr['C'] = {up, down, left};
    dr['D'] = {up, right, left};
    dr['E'] = {up, down, right};
    dr['F'] = {up, down, right, left};

    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    queue<pair<int, int>> qu;
    qu.push({sx, sy});

    vector<vector<int>> tvis(n, vector<int>(m, INT_MAX));
    tvis[sx][sy] = 0;

    while (qu.size())
    {
        auto [u, v] = qu.front();
        qu.pop();

        if (u == ex && v == ey) {
            cout << tvis[u][v];
            return 0;
        }

        for (auto [di, dj] : dr[arr[u][v]]) {
            int du = u + di;
            int dv = v + dj;

            if (du < 0 || du >= n || dv < 0 || dv >= m) continue;

            if (tvis[du][dv] <= tvis[u][v] + 1) continue;
            tvis[du][dv] = tvis[u][v] + 1;

            qu.push({du, dv});
        }
    }

    return 0;
}

