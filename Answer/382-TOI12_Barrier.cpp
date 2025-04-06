#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    scanf("%lld %lld", &n, &k);

    vector<int> pfs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%lld", &u);

        pfs[i] = pfs[i - 1] + u;
    }

    deque<int> dq; 
    int mx = 0, ml = LLONG_MAX;

    for (int i = 0; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();

        if (!dq.empty()) {
            int l = dq.front();
            int sum = pfs[i] - pfs[l];
            if (sum > mx) {
                mx = sum;
                ml = i - l;
            } else if (sum == mx) {
                ml = min(ml, i - l);
            }
        }

        while (!dq.empty() && pfs[dq.back()] >= pfs[i]) dq.pop_back();
        dq.push_back(i);
    }

    if (mx == 0) cout << "0\n0\n";
    else cout << mx << '\n' << ml << '\n';

    return 0;
}
