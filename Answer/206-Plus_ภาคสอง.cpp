/**
 *  Author: kutomei3
 *  Task: Plus ภาคสอง no.206
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> pfsr(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> pfsc(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pfsc[i][j] += pfsc[i][j - 1] + arr[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            pfsr[j][i] += pfsr[j - 1][i] + arr[j][i];
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << pfsr[n][v] + pfsc[u][m] - arr[u][v] << '\n';
    }

    return 0;
}
