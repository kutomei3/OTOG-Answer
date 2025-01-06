#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> all(n);
    for (auto& p : all) cin >> p;

    char c;
    int l = -1, r = n;

    int sum = 0;
    while (m--)
    {
        cin >> c;
        if (c == 'L') sum += all[++l];
        else if (c == 'R') sum += all[--r];
    }

    cout << sum;

    return 0;
}
