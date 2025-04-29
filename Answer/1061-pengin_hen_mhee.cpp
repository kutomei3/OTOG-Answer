/**
 * Author: kutomei3
 * date: 29-4-2025
**/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> ap[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld %lld", &u, &v);
        ap[u - 1].push_back(v);
        ap[v].push_back(u - 1);
    }

    vector<int> tvis(n + 1, -1);
    tvis[0] = 0;

    queue<int> qu;
    qu.push(0);

    while (qu.size()) {
        auto qf = qu.front();
        qu.pop();

        if (qf == n) break;
        for (auto p : ap[qf]) {
            if (tvis[p] == -1) {
                tvis[p] = tvis[qf] + 1;
                qu.push(p);
            }
        }
        if (qf != 0 && tvis[qf - 1] == -1) {
            tvis[qf - 1] = tvis[qf] + 1;
            qu.push(qf - 1);
        }
        if (qf != n && tvis[qf + 1] == -1) {
            tvis[qf + 1] = tvis[qf] + 1;
            qu.push(qf + 1);
        }
    }

    cout << tvis[n];

    return 0;
}
