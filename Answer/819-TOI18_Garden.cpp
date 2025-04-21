/**
 * Author: kutomei3
 * date: 21-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    vector<int> ans(n), s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s[s.size() - 1] < vec[i]) {
            s.push_back(vec[i]);
            ans[i] = s.size() - 1;
        }
        else {
            auto it = lower_bound(s.begin(), s.end(), vec[i]);
            *it = vec[i];
            ans[i] = it - s.begin();
        }
    }

    s.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty() || s[s.size() - 1] < vec[i]) {
            s.push_back(vec[i]);
            ans[i] = min(ans[i], (int)s.size() - 1);
        }
        else {
            auto it = lower_bound(s.begin(), s.end(), vec[i]);
            *it = vec[i];
            int va = it - s.begin();
            ans[i] = min(ans[i], va);
        }
    }

    while (q--) {
        int qi;
        cin >> qi;
        cout << ans[qi] << '\n';
    }

    return 0;
}
