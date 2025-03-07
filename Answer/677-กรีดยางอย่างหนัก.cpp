/**
 *  Author: kutomei3
 *  Task: กรีดยางอย่างหนัก no.677
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ch = 3, mh = 0;

int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

void dfs(vector<vector<char>> &arr, vector<vector<bool>> &vis, int i, int j)
{
    if (i == n - 1 && j == m - 1) {
        mh = max(mh, ch);
        return;
    }
    for (int p = 0; p < 4; p++) {
        int du = i + di[p];
        int dv = j + dj[p];

        if (du < 0 || du >= n || dv < 0 || dv >= m) continue;
        if (vis[du][dv]) continue;

        vis[du][dv] = true;
        ch += (arr[du][dv] == '*' ? 1 : arr[du][dv] == 'X' ? -1 : 0);

        dfs(arr, vis, du, dv);
        
        vis[du][dv] = false;
        ch -= (arr[du][dv] == '*' ? 1 : arr[du][dv] == 'X' ? -1 : 0);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[0][0] = true;

    dfs(arr, vis, 0, 0);

    cout << mh;

    return 0;
}
