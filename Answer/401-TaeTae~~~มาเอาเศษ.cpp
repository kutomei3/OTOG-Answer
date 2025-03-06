/**
 *  Author: kutomei3
 *  Task: TaeTae~~~มาเอาเศษ no.401
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string n;   
    int m;
    cin >> n >> m;

    int dt = 1, ans = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        ans += (n[i] - '0') * (dt %= m);
        dt *= 10;
    }

    cout << ans % m;

    return 0;
}

