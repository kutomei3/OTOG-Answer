/**
 *  Author: kutomei3
 *  Task: Plus ภาคแรก no.205
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, u, v;
    cin >> n >> m >> u >> v;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) sum += arr[i][v];
    for (int i = 1; i <= m; i++) sum += arr[u][i];

    cout << sum - arr[u][v];

    return 0;
}
