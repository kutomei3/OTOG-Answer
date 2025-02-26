#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &ad, vector<bool> &op, vector<bool> &rf, int k)
{
    queue<int> qu;
    qu.push(k);

    while (qu.size())
    {
        auto qf = qu.front();
        qu.pop();

        rf[qf] = true;

        for (auto& p : ad[qf]) {
            if (op[p] && !rf[p]) {
                qu.push(p);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> ad(n + 1), rad(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        ad[u].push_back(v);
        rad[v].push_back(u);
    }

    vector<pair<int, int>> ord(q);
    vector<bool> op(n + 1, true);
    for (int i = 0; i < q; i++) {
        cin >> ord[i].first >> ord[i].second;
        if (ord[i].first == 1) op[ord[i].second] = false;
    }

    vector<bool> rf1(n + 1, false), rfn(n + 1, false);
    bfs(ad, op, rf1, 1);
    bfs(rad, op, rfn, n);

    vector<int> ans;
    for (int i = q - 1; i >= 0; i--) {
        int k = ord[i].second;
        if (ord[i].first == 1)
        {
            op[k] = true;
            for (auto& p : rad[k]) {
                if (rf1[p]) {
                    rf1[k] = true;
                    break;
                }
            }
            for (auto& p : ad[k]) {
                if (rfn[p]) {
                    rfn[k] = true;
                    break;
                }
            }

            if (rf1[k]) bfs(ad, op, rf1, k);
            if (rfn[k]) bfs(rad, op, rfn, k);
        }
        else ans.push_back(op[k] && rf1[k] && rfn[k]);
    }

    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';

    return 0;
}
