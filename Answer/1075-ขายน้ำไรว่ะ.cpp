#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    vector<int> vis(1001, 0);
    int ans = 0;
    for (auto& p : vec) {
        if (vis[p]++ == 0) ans += p + 1;
        if (vis[p] == p + 1) vis[p] = 0;
    }

    cout << ans;
    
    return 0;
}
