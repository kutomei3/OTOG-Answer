#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(200001, false);
int cind[200001];
int lc(int ind, int ct) {
    if (vis[cind[ind]]) return ct;
    vis[cind[ind]] = true;
    return lc(cind[ind], ct + 1);
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        arr[i] = {u, i};
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cind[i] = arr[i].second;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        ans += lc(i, 0);
    }
    cout << ans;
    return 0;
}
