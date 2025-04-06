#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        int m, k;
        char c;
        cin >> m >> c >> k;
        vector<int> vec(26, 0);
        for (int i = 0; i < 26; i++) {
            int ct = 0;
            if (m < 26) {
                for (int j = 0; j < m; j++) {
                    if ((i + j + i * j) % 26 == c - 'A') ct++;
                }
            }
            else {
                for (int j = 0; j < 26; j++) {
                    int pa = (i + j + i * j) % 26;
                    if (pa == c - 'A') ct++;
                }
                ct *= m / 26;
                for (int j = 0; j < m % 26; j++) {
                    int pa = (i + j + i * j) % 26;
                    if (pa == c - 'A') ct++;
                }
            }
            vec[i] = ct;
        }

        int l = 0;
        for (auto& p : vec) l += p;

        int r = (k / l) - 1;
        int ans = 0;
        ans += r * 26;
        k -= r * l;
        for (int i = 0; i < 2700; i++) {
            if (k <= 0) break;
            int in = i % 26;
            k -= vec[in];
            ans++;
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}
