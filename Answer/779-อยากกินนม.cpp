#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        pq.push(u);
    }

    int ms = 0;
    while (k--) {
        int p = pq.top();
        ms += p;
        pq.pop();
        pq.push(p * 105 / 100);
    }

    cout << ms;

    return 0;
}
