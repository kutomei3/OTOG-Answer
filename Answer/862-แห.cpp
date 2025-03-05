/**
 *  Author: kutomei3
 *  Task: แห no.862
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    vector<int> ap(1000001, true);
    ap[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (!ap[i]) continue;
        for (int j = i + i; j <= 1000000; j += i) {
            ap[j] = false;
        }
    }

    int r = -1, pct = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        pct += ap[vec[i]];
        while (pct >= k) {
            mn = min(mn, i - r); 
            pct -= ap[vec[++r]]; 
        }
    }

    cout << mn;

    return 0;
}
