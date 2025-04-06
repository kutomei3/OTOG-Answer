#include <bits/stdc++.h>
using namespace std;

#define int long long

bool can(vector<int> &vec, int mid, int k)
{
    int ct = 0, mx = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < mid) ct++;
        else {
            int p = vec[i] / mid;
            ct += p;
            if (vec[i] % mid != 0) ct++;
        }
    }
    return (ct <= k);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    int l = 0;
    int r = INT_MAX;

    while (r > l) {
        int mid = (r + l) / 2;
        if (can(vec, mid, k)) r = mid;
        else l = mid + 1;
    }

    cout << l;

	return 0;
}
