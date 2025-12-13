#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, h, k;
    cin >> n >> h >> k;

    ll a[n];
    for (auto& p : a) cin >> p;
    
    priority_queue<int> pq;
    int ct = 0;
    for (int i = 0; i < n; i++) {
        ct++;
        h += a[i];
        if (a[i] < 0) pq.push(-a[i]);
        if (h <= 0) {
            if (k) {
                h += pq.top() * 2;
                pq.pop();
                k--;
            } else {
                h += pq.top();
                pq.pop();
                ct--;
            }
        }
    }

    cout << ct;

    return 0;
}

/*
aaabbaab


*/
