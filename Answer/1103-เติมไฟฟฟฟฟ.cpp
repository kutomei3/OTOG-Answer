#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> diff(N + 2, 0);
    for (int i = 0; i < K; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        diff[A] += C;
        if (B + 1 <= N) diff[B + 1] -= C;
    }

    int curr = 0, best = 0, ans = 0;
    for (int t = 1; t <= N; t++) {
        curr += diff[t];
        best = max(0LL, best + curr);
        ans = max(ans, best);
    }

    cout << ans;
    return 0;
}
