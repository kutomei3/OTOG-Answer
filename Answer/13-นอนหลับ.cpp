/**
 *  Author: kutomei3
 *  Task: นอนหลับ no.13
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> ae;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;

            ae.push_back({u, 2});
            ae.push_back({v, 1});
        }

        sort(ae.begin(), ae.end());

        int ct = 0;
        bool sa = false;
        for (int i = 0; i < ae.size(); i++) {
            if (ae[i].second == 1) ct--;
            else ct++;
            if (ct == n) sa = true;
        }

        cout << (sa ? "no\n" : "yes\n");
    }

    return 0;
}
