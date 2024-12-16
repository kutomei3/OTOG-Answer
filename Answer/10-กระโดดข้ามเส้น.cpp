#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, dis, mx = 0;
    cin >> n >> dis;

    vector<int> ans(n);
    for (int i = 0; i <n; i++) cin >> ans[i];

    for (int i = 0; i < n; i++) {
        int mx_1 = upper_bound(ans.begin(), ans.end(), ans[i] + dis) - ans.begin() - i - 1;
        mx = max(mx, mx_1);
    }

    cout << mx;

    return 0;
}
