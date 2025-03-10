/**
 *  Author: kutomei3
 *  Task: TOI20_Sculpture no.1015
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> aw(n + 1);
    for (int i = 1; i <= n; i++) cin >> aw[i].first >> aw[i].second;

    vector<int> mxt(n + 1, 0), mxb(n + 1, 0);

    vector<int> pre(n + 1, INT_MAX), cur(n + 1, INT_MAX);
    pre[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        cur = pre;
        for (int k = 1; k <= i; k++) {
            if (pre[k - 1] <= aw[i].second) {
                cur[k] = min(cur[k], pre[k - 1] + aw[i].first);
                mxt[i] = k;
            }
        }
        swap(pre, cur);
    }

    for (int i = 0; i <= n; i++) pre[i] = -1;
    pre[0] = INT_MAX;

    for (int i = n; i >= 1; i--) {
        cur = pre;
        for (int k = 1; k <= n; k++) {
            cur[k] = max(cur[k], min(pre[k - 1] - aw[i].first, aw[i].second));
            if (cur[k] == -1) {
                mxb[i] = k - 1;
                break;
            }
            else if (k == i) mxb[i] = k;
        }
        swap(pre, cur);
    }

    int mx = 0;
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (mxt[i] + mxb[i + 1] > mx) {
            mx = mxt[i] + mxb[i + 1];
            ans.clear();
            ans.push_back(i);
        }
        else if (mxt[i] + mxb[i + 1] == mx) ans.push_back(i);
    }

    cout << mx << '\n';
    for (auto& p : ans) cout << p << ' ';

    return 0;
}
