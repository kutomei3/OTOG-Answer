#include <bits/stdc++.h>
using namespace std;

#define int long long

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, f, q;
    cin >> n >> m >> f >> q;

    vector<vector<bool>> av(n, vector<bool>(m, false));
    
    vector<pair<int, int>> af(f + 1);
    for (int i = 1; i <= f; i++) {
        int u, v;
        scanf("%lld %lld", &u, &v);

        af[i] = {u, v};
    }

    vector<queue<pair<int, int>>> nc(f + 1);

    int ac = 0;
    vector<int> ad(n + m + 1, 0);

    vector<int> cf(2000001, 0);

    for (int i = 1; i <= n + m; i++) 
    {
        if (i <= f) {
            bool cp = false;
            for (int p = 0; p < 4; p++) {
                int du = af[i].first + di[p];
                int dv = af[i].second + dj[p];

                if (du < 0 || du >= n || dv < 0 || dv >= m) continue;
                if (av[du][dv]) cp = true;
            }

            cf[i] += cp;
            nc[i].push({af[i].first, af[i].second});
        }

        for (auto& qu : nc) 
        {
            int c = qu.size();
            while (c--) 
            {
                auto [u, v] = qu.front();
                qu.pop();

                if (av[u][v]) continue;
                av[u][v] = true;

                ac++;

                for (int p = 0; p < 4; p++) {
                    int du = u + di[p];
                    int dv = v + dj[p];

                    if (du < 0 || du >= n || dv < 0 || dv >= m) continue;
                    qu.push({du, dv});
                }
            }
        }

        ad[i] = ac;
        if (ac == n * m) {
            for (int j = i + 1; j < ad.size(); j++) {
                ad[j] = ac;
                if (j <= f) cf[j]++;
            }
            break;
        }
    }

    for (int i = n + m + 1; i <= f; i++) cf[i]++;

    int lc = max(n + m, f + 1);

    for (int i = 1; i <= lc; i++) {
        cf[i] += cf[i - 1] + (i < ad.size() ? ad[i] : n * m);
    }

    while (q--) {
        int d;
        cin >> d;

        cout << (d > lc ? cf[lc] + (d - lc) * n * m : cf[d]) << '\n';
    }

    return 0;
}
