#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string v, q;
    cin >> v >> q;

    int f = v[0] - '0', s = v[1] - '0', t = v[2] - '0';
    for (int i = 0; i < q.size(); i++) 
    {
        int n = q[i] - '0';

        n = (f + n - 1);
        if (n > 9) n %= 9;

        n = (s + n - 1);
        if (n > 9) n %= 9;

        n = (t + n - 1);
        if (n > 9) n %= 9;

        cout << n;

        f += v[0] - '0';
        if (f > 9) f %= 9;
        if (f == 0) f = 9;
        s -= 1;
        if (s == 0) s = 9;
        t += v[2] - '0';
        if (t > 9) t %= 9;
        if (t == 0) t = 9;
    }

    return 0;
}
