/**
 *  Author: kutomei3
 *  Task: ปริศนาค้นหาคำ no.19
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
bool fi = false;
void fw(vector<vector<char>> &arr, string s, int i, int j)
{
    int di[8] = {0, 0, -1, 1, 1, -1, -1, 1};
    int dj[8] = {1, -1, 0, 0, 1, -1, 1, -1};

    for (int p = 0; p < 8; p++) {
        fi = true;
        for (int k = 1; k < s.size(); k++) {
            int du = i + di[p] * k;
            int dv = j + dj[p] * k;

            if (du < 0 || du >= n || dv < 0 || dv >= m) {
                fi = false;
                break;
            }

            if (arr[du][dv] != s[k]) {
                fi = false;
                break; 
            }
        }

        if (fi) {
            cout << i << ' ' << j << '\n';
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            arr[i][j] = tolower(arr[i][j]);
        }
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        for (auto& c : s) c = tolower(c);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == s[0]) fw(arr, s, i, j);
                if (fi) break;
            }
            if (fi) break;
        }
        fi = false;
    }

    return 0;
}
