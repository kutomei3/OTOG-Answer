#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    int t, a, b, mt = 0;

    vector<vector<int>> all(100001, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        cin >> t >> a >> b;
        all[t][a] = b;
        mt = max(mt, t);
    }

    vector<vector<int>> mxt(mt + 1, vector<int>(n + 1, -1));

    mxt[0][s] = 0;
    for (int i = 0; i < mt; i++) {
        for (int j = 1; j <= n; j++) 
        {
            if (mxt[i][j] == -1) continue;

            mxt[i][j] += all[i][j];
            mxt[i + 1][j] = max(mxt[i + 1][j], mxt[i][j]);

            if (j - 1 > 0) 
                mxt[i + 1][j - 1] = max(mxt[i + 1][j - 1], mxt[i][j]);
            if (j + 1 <= n)
                 mxt[i + 1][j + 1] = max(mxt[i + 1][j + 1], mxt[i][j]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, mxt[mt][i] + all[mt][i]);

    cout << ans;

    return 0;
}

//unordered_map = memory exceed >:)
