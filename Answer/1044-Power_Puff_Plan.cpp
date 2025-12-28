#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> es;
int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

void fi(int n, int m)
{
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#' || vis[i][j]) continue;

            queue<pair<int, int>> qu;
            qu.push({i, j});

            int ct = 0;
            while (qu.size())
            {
                auto [u, v] = qu.front();
                qu.pop();

                if (vis[u][v]) continue;
                vis[u][v] = true;

                if (arr[u][v] == 'X') ct++;

                for (int p = 0; p < 4; p++) {
                    int du = di[p] + u;
                    int dv = dj[p] + v;

                    if (du < 0 || du >= n || dv < 0 || dv >= m) continue;
                    if (vis[du][dv] || arr[du][dv] == '#') continue;

                    qu.push({du, dv});
                }
            }

            mx = max(mx, ct);
        }
    }

    es.push_back(mx);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n, m;
    cin >> k >> n >> m;

    for (int i = 0; i < k; i++) {
        fi(n, m);
    }

    sort(es.rbegin(), es.rend());
    vector<int> pfs(k + 1, 0);
    for (int i = 1; i <= k; i++) pfs[i] = pfs[i - 1] + es[i - 1];

    int q;
    cin >> q;

    while (q--) {
        int qi;
        cin >> qi;

        auto it = lower_bound(pfs.begin(), pfs.end(), qi);
        if (it != pfs.end()) {
            cout << it - pfs.begin() << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}
