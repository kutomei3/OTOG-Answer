#include <bits/stdc++.h>
using namespace std;
 
#define int long long

vector<int> par(300003), siz(300003, 1);
int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}
void join(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    if (siz[px] < siz[py]) swap(px, py); 
    siz[px] += siz[py];
    par[py] = px;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    iota(par.begin(), par.end(), 0);
    siz[300002] = 0;

    int n, m, q;
    cin >> n >> m >> q;

    int arr[n + 2][m + 2];
    vector<vector<bool>> cvis(n + 2, vector<bool>(m + 2, true));
    vector<vector<int>> ind(n + 2, vector<int>(m + 2));
    array<int, 2> qa[q];
    for (int i = 0; i < q; i++) {
        cin >> qa[i][0] >> qa[i][1];
        qa[i][0]++, qa[i][1]++;
        cvis[qa[i][0]][qa[i][1]] = false;
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            ind[i][j] = i * (m + 2) + j;
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        siz[ind[i][m + 1]] = siz[ind[i][0]] = 0;
    }
    for (int j = 0; j <= m + 1; j++) {
        siz[ind[0][j]] = siz[ind[n + 1][j]] = 0;
    }

    int di[4] = {0, 0, -1, 1};
    int dj[4] = {1, -1, 0, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!cvis[i][j]) continue;
            
            for (int p = 0; p < 4; p++) {
                int du = i + di[p];
                int dv = j + dj[p];
                //if (du < 0 || du >= n + 2 || dv < 0 || dv >= m + 2) continue;
                if (!cvis[du][dv]) continue;
                join(ind[i][j], ind[du][dv]);
            }
        }
    }   

    //cout << siz[find(300002)] << '\n';
    for (int i = 0; i <= n + 1; i++) {
        join(300002, ind[i][m + 1]);
        join(300002, ind[i][0]);
    }
    for (int j = 0; j <= m + 1; j++) {
        join(300002, ind[0][j]);
        join(300002, ind[n + 1][j]);
    }

    vector<int> ans(q);
    for (int k = q - 1; k >= 0; k--) {
        ans[k] = siz[find(300002)];
        int i = qa[k][0], j = qa[k][1];
        cvis[i][j] = true;
        for (int p = 0; p < 4; p++) {
            int du = i + di[p];
            int dv = j + dj[p];
            //if (du < 0 || du >= n + 2 || dv < 0 || dv >= m + 2) continue;
            if (!cvis[du][dv]) continue;
            //cout << siz[find(160002)] << ' ' << i << ' ' << j << ' ' << du << ' ' << dv << '\n';
            join(ind[i][j], ind[du][dv]);
        }
    }

    for (auto& p : ans) cout << p << '\n';
 
    return 0;
}

/*
...
...
...
3 3 8
0 0
0 1
0 2
1 0
1 2
2 0
2 1
2 2

....
....
....
....
4 4 
*/
