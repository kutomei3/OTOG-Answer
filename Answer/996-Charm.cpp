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

    int n;
    cin >> n;

    vector<int> vec(n), ah(n);
    for (auto& p : vec) cin >> p;
    for (auto& p : ah) cin >> p;

    sort(vec.rbegin(), vec.rend());

    vector<int> mx(n), s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s[s.size() - 1] < ah[i]) {
            s.push_back(ah[i]);
            mx[i] = s.size();
        }
        else {
            auto it = lower_bound(s.begin(), s.end(), ah[i]);
            *it = ah[i];
            mx[i] = it - s.begin() + 1;
        }
    }

    priority_queue<int> pq;
    s.clear();

    for (int i = n - 1; i >= 0; i--) {
        if (s.empty() || s[s.size() - 1] < ah[i]) {
            s.push_back(ah[i]);
            pq.push(s.size() + mx[i]);
        }
        else {
            auto it = lower_bound(s.begin(), s.end(), ah[i]);
            *it = ah[i];
            pq.push(it - s.begin() + 1 + mx[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += pq.top() * vec[i];
        pq.pop();
    }

    cout << ans;

    return 0;
}
