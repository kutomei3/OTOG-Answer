/**
 * Author: kutomei3
 * date: 7-4-2025
**/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
struct fentree {
    int n;
    vector<int> b;
 
    fentree(int s) {
        n = s;
        b.assign(n + 2, 0);
    }
 
    void update(int ind, int va) {
        for (++ind; ind <= n; ind += ind & -ind) {
            b[ind] += va;
        }
    }
 
    int calq(int ind) {
        int res = 0;
        for (++ind; ind > 0; ind -= ind & -ind) {
            res += b[ind];
        }
        return res;
    }
 
    int rq(int l, int r) {
        return calq(r) - calq(l - 1);
    }
};
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k;
    cin >> k >> n;
 
    fentree ft(n + 2);
 
    while (k--) {
        int o;
        cin >> o;
 
        if (o == 2) {
            int u;
            cin >> u;
            cout << ft.calq(u) << '\n';
        }
        else {
            int a, b;
            cin >> a >> b;
            ft.update(a, 1);
            ft.update(b + 1, -1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ft.calq(i) << ' ';
    }
 
    return 0;
}
