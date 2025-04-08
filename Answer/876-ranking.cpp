/**
 * Author: kutomei3
 * date: 8-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    oset<int> ods;
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        ods.insert(u);
    }

    for (int i = 0; i < n - m; i++) {
        int u;
        cin >> u;
        ods.insert(u);
        cout << ods.order_of_key(u) + 1 << '\n';
    }

    return 0;
}
