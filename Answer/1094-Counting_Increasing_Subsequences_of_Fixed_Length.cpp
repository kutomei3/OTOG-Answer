#include <bits/stdc++.h>
using namespace std;

#define int long long

int md = 1e9 + 7;

int b[51][200005];
int n, co = 0;
void upd(int ind, int val, int k) {
    for (; ind <= co + 1; ind += ind & -ind) {
        int tmp = b[k][ind] + val;
        if (tmp >= md) tmp -= md;
        b[k][ind] = tmp;
    }
}
int qa(int ind, int k) {
    int res = 0;
    for (; ind > 0; ind -= ind & -ind) {
        res += b[k][ind];
        if (res >= 1LL << 60) res %= md;
    }
    return res % md;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto& p : arr) cin >> p;
    vector<int> comp = arr;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    co = comp.size();
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            int ss = (j == 1 ? 1 : qa(arr[i] - 1, j - 1));
            upd(arr[i], ss, j);
        }
    }

    cout << qa(co, k) << ' ';
    
    return 0;
}
