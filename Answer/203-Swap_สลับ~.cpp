#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;

    cin >> n >> m;

    vector<int> all(n);

    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        swap(all[--x], all[--y]);
    }

    for (const int &p : all) {
        cout << p << ' ';
    }

    return 0;
}
