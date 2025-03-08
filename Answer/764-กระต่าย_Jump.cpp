/**
 *  Author: kutomei3
 *  Task: กระต่าย Jump no.764
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec[i];

    vector<int> tvis(n + 1, 0);

    int i = 1;
    while (i <= m) {
        if (tvis[s]) i += (i - tvis[s]) * ((m - i) / (i - tvis[s])); 
        tvis[s] = i++;
        s += vec[s];
    }

    cout << s;

    return 0;
}
