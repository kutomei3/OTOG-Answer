#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pas(1000001, 0);
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;

        pas[u] = i;
    }

    vector<int> chak(1000001, 0);
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;

        if (i < pas[u]) chak[i + (n - pas[u])]++;
        else chak[i - pas[u]]++;
    }

    int mx = INT_MIN, in;
    for (int i = 0; i <= n; i++) {
        if (chak[i] > mx) {
            mx = chak[i];
            in = i;
        }
    }

    cout << mx << ' ' << in;

    return 0;
}
