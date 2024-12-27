#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, v;
    cin >> n;

    vector<int> od, ev;

    for (int i = 0; i < n; i++) {
        cin >> v;
        if (v & 1) od.push_back(v);
        else ev.push_back(v); 
    }

    sort(od.rbegin(), od.rend());
    sort(ev.begin(), ev.end());

    for (auto& p : ev) cout << p << ' ';
    for (auto& p : od) cout << p << ' ';

    return 0;
}
