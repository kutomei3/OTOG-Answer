/**
 *  Author: kutomei3
 *  Task: พลัง Math no.200
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) cout << 1;
    else if (a * a + b * b == c * c) cout << 2;
    else cout << "NO";

    return 0;
}
