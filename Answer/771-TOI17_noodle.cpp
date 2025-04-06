#include <bits/stdc++.h>
using namespace std;

#define int long long

bool can(vector<int>& vec, int mid, int m, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0, ct = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        pq.push(vec[i]);
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k && sum >= mid) {
            sum = 0, ct++;
            while (pq.size()) pq.pop();
        }
    }
    return (ct < m);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    int l = 0;
    int r = INT_MAX;

    while (r > l) {
        int mid = (r + l) / 2;
        if (can(vec, mid, m, k)) r = mid;
        else l = mid + 1;
    }

    cout << l - 1;

    return 0;
}
