#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n + 2, vector<int>(m + 2, 0));
    vec[1][1] = 1;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            vec[i][j] += vec[i - 1][j] + vec[i][j - 1];
            vec[i][j] %= 100000003;
        }
    }

    cout << vec[n + 1][m + 1];

    return 0;
}

//nCr?
