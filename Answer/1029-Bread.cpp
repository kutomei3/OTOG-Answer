#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> br1(n), br2(n);

    for (int i = 0; i < n; i++) cin >> br1[i];
    for (int i = 0; i < n; i++) cin >> br2[i];

    vector<bool> vis(n, false);
    vector<int> ans(n);

    bool bak = false;
    int last = n - 1;
    int fir = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[br1[i]]) {
            vis[br1[i]] = true;

            if (bak) ans[last--] = br1[i];
            else ans[fir++] = br1[i];
        }
        bak = !bak;

        if (!vis[br2[i]]) {
            vis[br2[i]] = true;

            if (bak) ans[last--] = br2[i];
            else ans[fir++] = br2[i];
        }
        bak = !bak;
    }
    //can be recur here

    for (auto& p : ans) cout << p << '\n';

    return 0;
}
//greedy solution
