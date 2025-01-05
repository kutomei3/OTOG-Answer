#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> up(n);
    vector<int> inv_down(n + 1, 0);

    for (auto& p : up) cin >> p; 

    int p;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        inv_down[p] = i; 
    }

    queue<array<int, 3>> qu;
    qu.push({0, 0, 0});

    int mxi = 0;

    vector<int> mxa(n, -1);

    while (!qu.empty())
    {
        auto [pos, mx, tim] = qu.front();
        qu.pop();

        if (pos == n) {
            mxi = max(mxi, tim);
            continue;
        }
        
        if (mx < inv_down[up[pos]] && tim > mxa[pos]) {
            mxa[pos] = tim;
            qu.push({pos + 1, inv_down[up[pos]], tim + 1});
        }

        qu.push({pos + 1, mx, tim});
    }

    cout << mxi;

    return 0;
}
