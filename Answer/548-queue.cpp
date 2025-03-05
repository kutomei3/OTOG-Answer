/**
 *  Author: kutomei3
 *  Task: queue no.548
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> qu;
    while (n--) {
        string s;
        cin >> s;

        if (s == "push") {
            int u;
            cin >> u;

            qu.push(u);
        }
        if (s == "pop") {
            if (qu.size()) cout << qu.front() << '\n', qu.pop();
            else cout << "null\n";
        }
    }

    return 0;
}
