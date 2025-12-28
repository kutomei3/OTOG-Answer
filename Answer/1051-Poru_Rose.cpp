#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
bool ca(int x, int y) {
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> n >> m >> k;

    vector<vector<char>> arr(n, vector<char>(m, '.'));
    while (k--) {
        int u, v, s;
        cin >> u >> v >> s;
        arr[u][v] = '#';
        for (int p = 1; p <= s; p++) {
            int i = p, j = 0;
            while (i > 0) {
                int x1 = u + i, y1 = v + j;
                int x2 = u - j, y2 = v + i;
                int x3 = u - i, y3 = v - j;
                int x4 = u + j, y4 = v - i;
                if (ca(x1, y1) && arr[x1][y1] == '.') arr[x1][y1] = '*';
                if (ca(x2, y2) && arr[x2][y2] == '.') arr[x2][y2] = '*';
                if (ca(x3, y3) && arr[x3][y3] == '.') arr[x3][y3] = '*';
                if (ca(x4, y4) && arr[x4][y4] == '.') arr[x4][y4] = '*';
                i--, j++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}
