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

        vector<int> temp;
        for (int i = l; i <= r; i++) temp.push_back(all[i]);

        sort(temp.begin(), temp.end());

        for (auto& p : temp) cout << p << ' ';
        cout << '\n';
    }

    return 0;
}
