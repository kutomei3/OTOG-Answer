#include <bits/stdc++.h>
using namespace std;

#define int long long

const int md = 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n %= md;

    cout << (((n * n) % md) * n) % md;

    return 0;
}
