/**
 * Author: kutomei3
 * date: 20-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%lld", &n);

    vector<int> vec(n + 2);
    vec[0] = -1, vec[n + 1] = -1;
    for (int i = 1; i <= n; i++) scanf("%lld", &vec[i]);

    deque<int> mnd;
    mnd.push_back(0);

    vector<int> mfl(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        while (vec[i] <= vec[mnd.front()]) {
            cur -= (mnd[0] - mnd[1]) * vec[mnd.front()];
            mnd.pop_front();
        }
        cur += (i - mnd.front()) * vec[i];
        mnd.push_front(i);

        mfl[i] = cur;
    }

    mnd.clear();
    mnd.push_back(n + 1);
    cur = 0;

    int mx = 0;
    for (int i = n; i >= 1; i--) {
        while (vec[i] <= vec[mnd.front()]) {
            cur -= (mnd[1] - mnd[0]) * vec[mnd.front()];
            mnd.pop_front();
        }
        cur += (mnd.front() - i) * vec[i];
        mnd.push_front(i);

        mx = max(mx, mfl[i] + cur - vec[i]);
    }

    printf("%lld", mx);

    return 0;
}
