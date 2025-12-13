#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t = 0;
vector<int> ass(500005, 0);
void dfs(vector<int> ap[], int c, int par) {
    int tf = t;
    for (auto& p : ap[c]) {
        if (p != par) {
            dfs(ap, p, c);
            t++;
        }
    }
    t++;
    ass[c] = (t - tf) >> 1;
}

int main() 
{
    int n;
    scanf("%d", &n);

    vector<int> ap[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        ap[u].push_back(v);
        ap[v].push_back(u);
    }

    dfs(ap, 0, -1);
    for (int i = 0; i < n; i++) printf("%d ", ass[i] + 1);

    return 0;
}

/*


*/
