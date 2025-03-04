#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    int l = 0;
    int r = n - 1;

    int ma = 0;
    while (r > l) {
        ma = max(ma, min(vec[l], vec[r]) * (r - l));

        if (vec[r] > vec[l]) l++;
        else r--;
    }

    cout << ma;

    return 0;
}
