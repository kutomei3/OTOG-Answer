#include<bits/stdc++.h>
using namespace std;

#define int long long

bool can(vector<int> &all, int m, int k)
{
    int sum = 0, ct = 0;
    
    for (int i = 0; i < all.size(); i++) {
        if (ct == k) return true;
        sum += all[i];
        if (sum >= m) {
            ct++;
            sum = 0;
        }
    }
    
    return (ct > k);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> all(n);
    for (auto& p : all) cin >> p;
    
    int k;
    while (q--)
    {
        cin >> k;
    
        int l = 1;
        int r = 10e17;
    
        while (r > l) {
            int mid = (l + r) / 2;
            if (!can(all, mid, k)) r = mid;
            else l = mid + 1;
        }    
        
        cout << (n == k ? 0 : l) << '\n';
    }    
    
    return 0;
}
