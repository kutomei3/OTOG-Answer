/**
 *  Author: kutomei3
 *  Task: กระโดดทีหัวใจจะวาย no.795
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int m, h, ap = -1;
void rec(int am) {
    if (ap == 1 && am == m) return;
    cout << am << ' ';
    if (am < h) cout << "PULL " << am << ' ', ap = 1;
    return rec(am + (h * ap));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> h;
    rec(m);

    cout << m;

    return 0;
}
