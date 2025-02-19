#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, n, l;
    cin >> n >> l >> a >> b;

    vector<int> all(n);
    for (auto& p : all) cin >> p;

    sort(all.begin(), all.end());

    multiset<int> msa, msb;
    for (int i = 0; i < a; i++) msa.insert(all[i]);
    for (int i = a; i < b; i++) msb.insert(all[i]);

    while (l--)
    {
        int v1 = *msb.rbegin() - *msa.rbegin();
        int v2 = (*msb.rbegin() + *msa.rbegin()) / 2;

        msb.insert(v2);
        if (v1 > *msa.rbegin()) {
            msa.erase(prev(msa.end()));
            msb.insert(v1);
            msa.insert(*msb.begin());
            msb.erase(msb.begin());
        }
        else {
            msa.erase(prev(msa.end()));
            msa.insert(v1);
        }

        msb.erase(prev(msb.end()));
    }

    for (auto& p : msa) cout << p << ' ';
    for (auto& p : msb) cout << p << ' ';
    for (int i = b; i < n; i++) cout << all[i] << ' ';

    return 0;
}
