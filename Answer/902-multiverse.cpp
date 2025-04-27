/**
 * Author: kutomei3
 * date: 27-4-2025
**/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> vec(n + 1);
        for (int i = 1; i <= n; i++) cin >> vec[i];

        vector<bool> vis(n + 1, false);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vis[i] = true;

            if (vec[i] == i) {
                mx = max(mx, 1ll); 
                break;
            }
            int ct = 1, cur = i;
            while (vec[cur] != i) {
                vis[cur] = true;
                cur = vec[cur];
                ct++;
            }
            if (ct & 1) mx = max(mx, 3ll);
            else mx = max(mx, 2ll);
        }

        cout << mx << '\n';
    }
 
    return 0;
}
