#include <bits/stdc++.h>
using namespace std;

#define int long long

int can(vector<int> arr, int n, int mid, int x, int y, int m) {
    int ct = 0;
    vector<int> dmn(n, 0);
    int da = 0;
    //cout << "JERE";
    //cout << mid << '\n';
    for (int i = 0; i < n; i++) arr[i] = max(0ll, arr[i] - mid * x);
    for (int i = 0; i < n; i++) {
        da -= dmn[i];
        arr[i] -= da;
        if (arr[i] > 0) {
            int t = (arr[i] + y - 1) / y;
            ct += t;
            //cout << i << ' ' << t << '\n';
            da += t * y;
            if (i + 2 * m + 1 < n) dmn[i + 2 * m + 1] += t * y; 
        }
    }
    //cout << mid << '\n';
    //cout << (mid >= ct ? 0 : 1) << '\n';
    return mid >= ct;
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> arr(n);
    for (auto& p : arr) cin >> p;

    int l = 0;
    int r = 1e10;
    while (r > l) {
        int mid = (r + l) >> 1;
        //cout << r << ' ' << l << '\n';
        //for (auto& p : arr) cout << p << ' ';
        if (can(arr, n, mid, x, y - x, m)) r = mid;
        else l = mid + 1;
    }

    cout << l;

    return 0;
}
