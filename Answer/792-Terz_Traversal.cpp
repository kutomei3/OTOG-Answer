/**
 *  Author: kutomei3
 *  Task: Terz Traversal no.792
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

    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int pi = 0, pj = 0;
    while (s--) {
        char c;
        cin >> c;

        if (c == 'D') pi += 1;
        else if (c == 'U') pi -= 1;
        else if (c == 'R') pj += 1;
        else if (c == 'L') pj -= 1;
    }

    cout << arr[pi][pj];

    return 0;
}
