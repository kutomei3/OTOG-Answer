/**
 *  Author: kutomei3
 *  Task: TOI20_Bit_String no.1016
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, q;
vector<int> val(1050000);
vector<int> mxv(1050000, LLONG_MIN);

int dfs(int s)
{
    if (mxv[s] != LLONG_MIN) return mxv[s];
    for (int i = n - 1; i >= 0; i--) {
        if (s & (1 << i)) {
            mxv[s] = max(mxv[s], dfs(s & (~(1 << i))));
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if ((s & (1 << i)) && (s & (1 << (i - 1)))) {
            mxv[s] = max(mxv[s], dfs(s & (~((1 << (i - 1)) | (1 << i)))));
        }
    }
    mxv[s] += val[s];
    return mxv[s];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i < (1 << n); i++) {
        string s;
        int v;
        cin >> s >> v;

        val[stoi(s, nullptr, 2)] = v;
    }

    mxv[0] = 0;
    val[(1 << n) - 1] = dfs((1 << n) - 1);

    while (q--) {
        string s;
        cin >> s;

        cout << mxv[stoi(s, nullptr, 2)] << '\n';
    }

    return 0;
}
