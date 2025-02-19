#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<int> aen;
    int sqn = sqrt(n);
    for (int i = 1; i <= sqn; i++) {
        if (n % i == 0) {
            aen.push_back(i);
            aen.push_back(n / i);
        }
    }

    sort(aen.rbegin(), aen.rend());

    vector<bool> c(5000001, true);
    int mn = aen[0]; c[aen[0]] = false;
    for (int i = 0; i < aen.size(); i++) {
        if (!c[aen[i]]) continue;
        
        string t;
        for (int j = 0; j < aen[i]; j++) t += s[j];

        int p = 0;
        bool can = true;
        for (int j = aen[i]; j < n; j++) {
            if (s[j] != t[p]) {
                can = false;
                break;
            }
            p++;
            if (p == t.size()) p = 0;
        }

        if (can) mn = aen[i];
        else {
            int sqen = sqrt(aen[i]);
            for (int j = 1; j <= sqen; j++) {
                if (aen[i] % j == 0) {
                    c[j] = false;
                    c[aen[i] / j] = false;
                }
            }
        }
    }

    cout << mn;

    return 0;
}
