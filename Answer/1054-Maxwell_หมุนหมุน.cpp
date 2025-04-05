/**
 * Author: kutomei3
 * file: see u TOI21
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int bgcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec[i];

    vector<int> mg(n + 1, -1);
    vector<pair<int, int>> mpf(n + 1, {-1, -1});
    for (int i = 1; i <= n; i++) {
        mpf[i] = mpf[i - 1];
        int cgd = mg[bgcd(i, n)];
        if (cgd != -1) {
            if (cgd * i > mpf[i - 1].second) {
                mpf[i] = {i, cgd * i};
            }
        }
        else {
            int sum = 0, cind = i, cl = (n % i == 0 ? n / i : n);
            while (cl--) {
                sum += vec[cind];
                cind += i;
                if (cind > n) cind -= n;
            }
            mg[bgcd(i, n)] = sum;
            if (sum * i > mpf[i - 1].second) {
                mpf[i] = {i, sum * i};
            }
        }
    }

    while (q--) {
        int qi;
        cin >> qi;
        cout << mpf[qi].first << ' ' << mpf[qi].second << '\n';
    }

    return 0;
}
