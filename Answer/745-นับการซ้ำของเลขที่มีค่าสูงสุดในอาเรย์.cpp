#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    int mx = INT_MIN;

    for (auto& p : arr) {
        cin >> p;
        mx = max(mx, p);
    }

    int ct = 0;
    for (auto& p : arr)
        if (p == mx) ct++;

    cout << ct;

    return 0;
}
