#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, m, qs;
    cin >> n >> q;

    vector<int> maxd(n + 1);
    maxd[0] = INT_MIN;

    int cur_sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        cur_sum += m;

        maxd[i] = max(maxd[i - 1], cur_sum);
    }

    while (q--) {
        cin >> qs;

        if (lower_bound(maxd.begin(), maxd.end(), qs) != maxd.end())
        {
            int dat = lower_bound(maxd.begin(), maxd.end(), qs) - maxd.begin() - 1;
            cout << dat << '\n';
        }
        else cout << -1 << '\n';
    }

    return 0;
}
