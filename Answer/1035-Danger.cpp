#include <bits/stdc++.h>
using namespace std;

#define int long long
//fix int limit

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r, v;
    char c;
    string s;

    cin >> n >> s >> m;

    vector<int> val(26, 0);

    for (int i = 0; i < m; i++) {
        cin >> c >> v;
        val[c - 'A'] = v;
    }

    cin >> r;

    vector<int> ps(n + 1);
    ps[0] = 0;

    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + val[s[i - 1] - 'A'];

    vector<int> ouc(26, 0);
    for (int i = 0; i < r; i++) ouc[s[i] - 'A']++;

    int mxo = 1, mx_co;
    for (int i = 0; i < 26; i++) {
        if (ouc[i] > mxo) {
            mxo = ouc[i];
            mx_co = i;
        }
        else if (ouc[i] == mxo) mx_co = 26;
    }

    int max_sum = ps[r] - (mx_co != 26 ? val[mx_co] * ouc[mx_co] : 0);

    for (int i = r; i < n; i++) {
        ouc[s[i - r] - 'A']--;
        ouc[s[i] - 'A']++;

        int mx = 1, mx_c;
        for (int j = 0; j < 26; j++) {
            if (ouc[j] > mx) {
                mx = ouc[j];
                mx_c = j;
            }
            else if (ouc[j] == mx) mx_c = 26;
        }

        int sum = ps[i + 1] - ps[i + 1 - r] - (mx_c != 26 ? val[mx_c] * ouc[mx_c] : 0);
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;

    return 0;
}

//ngl but sliding window is too hard and complex
//prefix solution is enough
