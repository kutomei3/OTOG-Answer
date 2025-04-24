/**
 * Author: kutomei3
 * date: 24-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bitset<1000007> bs;
    bs[0] = 1;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        bs |= (bs << u);
    }

    int qi;
    while (cin >> qi) {
        cout << (bs[qi] ? "YES\n" : "NO\n");
    }

    return 0;
}
