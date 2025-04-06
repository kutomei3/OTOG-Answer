#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n;
    scanf("%lld", &n);

    vector<int> a(n), b(n);
    for (auto& p : a) scanf("%lld", &p);
    for (auto& p : b) scanf("%lld", &p);
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    vector<int> vec(n);
    for (int i = 0; i < n; i++) vec[i] = a[i] + b[i];

    sort(vec.begin(), vec.end());
    printf("%lld", vec[n - 1] - vec[0]);

    return 0;
}
