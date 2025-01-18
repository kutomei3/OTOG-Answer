#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

bool can(int mid, vector<int> &all, int m) 
{
    int ct = 0;
    for (auto& p : all) 
        ct += mid / p;
    
    return ct >= m;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int l = 0;
    int r = ULLONG_MAX;

    vector<int> all(n);
    for (auto& p : all) cin >> p;

    while (r > l) {
        int mid = (l + r) / 2;
        if (can(mid, all, m)) r = mid;
        else l = mid + 1;
    }

    cout << l;

    return 0;
}
