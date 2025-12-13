#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> lis;
void dfs(vector<int> &liss, vector<int> ap[], vector<int> &ah, int c, int par)
{
    //cout << "HERE";
    for (auto& p : ap[c]) {
        if (p == par) continue;

        int ind = lower_bound(lis.begin(), lis.end(), ah[p]) - lis.begin();
        liss[p] = ind + 1;
        if (ind == lis.size()) {
            lis.push_back(ah[p]);
            dfs(liss, ap, ah, p, c);
            lis.pop_back();
        } else {
            int old = lis[ind];
            lis[ind] = ah[p];
            dfs(liss, ap, ah, p, c);
            lis[ind] = old;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s, t;
    cin >> n >> s >> t;

    vector<int> ah(n + 1);
    for (int i = 1; i <= n; i++) cin >> ah[i];

    vector<int> ap[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ap[u].push_back(v);
        ap[v].push_back(u);
    }

    vector<int> list(n + 1);
    list[t] = 1;
    //liss[1] = 1;
    lis.push_back(ah[t]);
    dfs(list, ap, ah, t, -1);

    lis.clear();

    for (int i = 1; i <= n; i++) ah[i] *= -1;

    vector<int> liss(n + 1);
    liss[s] = 1;
    lis.push_back(ah[s]);
    dfs(liss, ap, ah, s, -1);

    //for (int i = 1; i <= n; i++) cout << liss[i] << ' ';

    // vector<int> list;
    // dfs(list, ap, ah, t, -1);

    int q;
    cin >> q;
    while (q--) {
        int u;
        cin >> u;
        cout << liss[u] + list[u] - 1 << '\n';
    }

    return 0;
}

/*
2
3
+3 +9 +3 +33 +3 +9 +3 +129 +3 +9 +3 +33 +3 +9 +3 +513
1 100 1101 10000 110001 1111000 
1 4 13 16 49 52 61 64 193 +2
3 2     
    5 8
    7 6
33        17


*/
