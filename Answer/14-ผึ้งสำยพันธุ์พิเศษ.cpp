/**
 *  Author: kutomei3
 *  Task: ผึ้งสำยพันธุ์พิเศษ no.14
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> d(25);
    d[0] = {1, 2};

    for (int i = 1; i <= 24; i++) {
        d[i] = {d[i - 1].second, d[i - 1].first + d[i - 1].second + 1};
    }

    while (true)
    {
        int cd;
        cin >> cd;
        if (cd == -1) break;
        cout << d[cd].first << ' ' << d[cd].second << '\n';
    }

    return 0;
}

