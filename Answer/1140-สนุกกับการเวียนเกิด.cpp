#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pll pair<int, int>

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    while (q--) {
        int k;
        cin >> k;
        k--;
        int ans = 0;
        for (int i = 0; i < 62; i += 2) {
            int ind = k & (1ll << i), sec = k & (1ll << (i + 1));
            //cout << sec << ' ' << ind << ' ';
            if (sec && ind) ans |= (1ll << i);
            else if (sec && !ind) ans |= ((1ll << i) | (1ll << (i + 1)));
            else if (!sec && ind) ans |= (1ll << (i + 1));
            //cout << ans << '\n';
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}

/*
dp[i][k] += dp[p][k - 1]
00 -> 00
01 -> 11
10 -> 01
11 -> 10



*/
