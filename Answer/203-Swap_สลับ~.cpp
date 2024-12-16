#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, l, r;

    cin >> n >> q;

    vector<int> all(n);
    for (int i = 0; i < n; i++) cin >> all[i];

    while (q--) 
    {
        cin >> l >> r;
        swap(all[--l], all[--r]);
    }

    for (auto& p : all) cout << p << ' ';

    return 0;
}
