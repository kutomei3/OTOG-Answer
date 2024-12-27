#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, cmd;
    cin >> n >> cmd;

    vector<int> vec(n);
    for (auto& p : vec) cin >> p;

    if (cmd) sort(vec.rbegin(), vec.rend());
    else sort(vec.begin(), vec.end());

    for (auto& p : vec) cout << p << ' ';

    return 0;
}
