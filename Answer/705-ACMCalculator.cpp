/**
 *  Author: kutomei3
 *  Task: ACMCalculator no.705
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
        int c;
        cin >> c;

        int pt = 0, p;
        while (c--) {
            int u;
            string s;
            cin >> s >> u;

            if (s == "AC") p = u;
            else pt += 20;
        }

        cout << p + pt << '\n';
    }

    return 0;
}
