/**
 * Author: kutomei3
 * date: 21-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<char> lan(n + 1);
    for (int i = 1; i <= n; i++) cin >> lan[i];

    vector<int> ap[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ap[u].push_back(v);
        ap[v].push_back(u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    vector<int> mn(n + 1, INT_MAX);
    mn[1] = 0;

    while (pq.size())
    {
        auto [w, u] = pq.top();
        pq.pop();

        for (auto& v : ap[u]) {
            if (mn[v] > w + 2) {
                mn[v] = w + 2;
                pq.push({mn[v], v});
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> ac[26];
    for (int i = 1; i <= n; i++) {
        ac[lan[i] - 'A'].push(mn[i]);
    }

    int ca = 0;
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        if (ac[c - 'A'].empty()) {
            cout << -1;
            return 0;
        }
        ca += ac[c - 'A'].top();
        ac[c - 'A'].pop();
    }

    cout << ca;

    return 0;
}
