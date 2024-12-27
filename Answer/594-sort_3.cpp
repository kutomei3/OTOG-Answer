#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> vec(n);
    for (auto& s : vec) cin >> s;

    sort(vec.begin(), vec.end());

    for (auto& s : vec) cout << s << '\n';

    return 0;
}
