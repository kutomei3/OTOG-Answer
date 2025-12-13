#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, s, l;
    cin >> n >> s >> l;

    ll pos[n + 1], val[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &pos[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &val[i]); 
        val[i] += val[i - 1];
    }

    ll ans = 0;
    deque<pair<ll, int>> dqp, dqs;
    dqp.push_front({0ll, pos[1]});
    for (int i = 1; i <= n; i++) {
        dqs.push_back({val[i-1], pos[i]});
        while (dqs.size() && (pos[i] - dqs.front().second + 1 >= s || i == n)) {
            auto ps = dqs.front(); dqs.pop_front();
            while (dqp.size() && ps.first <= dqp.back().first) dqp.pop_back();
            dqp.push_back(ps);
        }
        while (dqp.size() && pos[i] - dqp.front().second + 1 > l) dqp.pop_front();
        
        //cout << val[i] << ' ' << dqp.front().first << '\n';
        if (dqp.size()) ans = max(ans, val[i] - dqp.front().first);
        else ans = max(ans, val[i] - val[i - 1]);
        //if (pos[n] - pos[i] <= l) ans = max(ans, val[n] - val[i - 1]);
    }

    cout << ans;
    
    return 0;
}

/*
deque -> min(


*/
