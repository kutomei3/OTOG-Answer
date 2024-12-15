#include <bits/stdc++.h>
using namespace std;

#define int long long
//fix int limit

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, l, r;
    cin >> n >> q;

    vector<int> power(n + 2);
    power[0] = power[n + 1] = 0;
    for (int i = 1; i <= n; i++) cin >> power[i];

    vector<int> danger(n);
    int ws = power[0] + power[1] + power[2];
    for (int i = 0; i < n; i++) {
        danger[i] = ws;
        ws -= power[i] - power[i + 3];
    }
    //find danger using window slide

    sort(danger.begin(), danger.end());

    while (q--) {
        cin >> l >> r;

        int low = lower_bound(danger.begin(), danger.end(), l) - danger.begin();
        int high = upper_bound(danger.begin(), danger.end(), r) - danger.begin();
        //prefix sum in danger

        cout << high - low << '\n';
    }

    return 0;
}
