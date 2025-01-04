#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b, k, q;
    cin >> n >> m >> b >> k >> q;

    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> allb(b);
    for (auto& [u, v] : allb) cin >> u >> v; 

    int qn, qm;
    while (q--)
    {
        cin >> qn >> qm;

        int ct = 0;
        for (auto& p : allb)
            if (abs(qn - p.first) + abs(qm - p.second) <= k) ct++; 

        cout << (arr[qn][qm] - ct < 0 ? 0 : arr[qn][qm] - ct) << '\n';
    }

    return 0;
}

//dont be fool be creative
