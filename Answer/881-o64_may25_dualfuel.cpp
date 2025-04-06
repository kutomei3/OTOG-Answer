#include <bits/stdc++.h>
using namespace std;

#define int long long

int mdq(vector<int> &vec, int v) {
    int ans = 0;
    deque<int> dq;
    for (int i = 0; i < vec.size(); i++) {
        if (!dq.empty() && dq.front() <= i - v) dq.pop_front();
        while (!dq.empty() && vec[dq.back()] >= vec[i]) dq.pop_back();
        
        dq.push_back(i);
        ans += vec[dq.front()];
    }

    return ans;
}

signed main() {
    int n, v;
    scanf("%lld %lld", &n, &v);

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    printf("%lld", mdq(a, v) + mdq(b, v));

    return 0;
}
