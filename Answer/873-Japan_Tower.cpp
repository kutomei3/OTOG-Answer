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

    int n;
    cin >> n;

    oset<pair<int, int>> ods;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        ods.insert({u, i});
        cout << ods.order_of_key({u, i}) << ' ';
    }

    return 0;
}
