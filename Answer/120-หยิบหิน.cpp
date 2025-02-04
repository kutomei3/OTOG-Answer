#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> almx(2 * n, vector<int>(2 * n, -1));

    vector<int> all(2 * n);
    for (auto& p : all) cin >> p;

    queue<array<int, 3>> qu;
    qu.push({0, 2 * n - 1, 0});

    while (qu.size())
    {
        auto [l, r, v] = qu.front();
        qu.pop();

        if (l > r || v <= almx[l][r]) continue;
        almx[l][r] = v;

        qu.push({l + 1, r, (l + r & 1 ? v + all[l] : v)});
        qu.push({l, r - 1, (l + r & 1 ? v + all[r] : v)});
    }

    int mx = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            mx = max(mx, almx[i][j]);
        }
    }

    cout << mx;

    return 0;
}
