#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, u, l, r;
    cin >> n >> q;

    vector<int> ps(n + 1);
    ps[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> u;
        ps[i] = ps[i - 1] + u;
    }

    while (q--)
    {
        cin >> l >> r;
        cout << ps[r] - ps[--l] << '\n';
    }

    return 0;
}
