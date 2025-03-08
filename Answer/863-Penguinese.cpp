/**
 *  Author: kutomei3
 *  Task: Penguinese no.863
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

    deque<string> lw, rw;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        rw.push_back(s);
    }

    int cm = 2 * n - 1;
    while (cm--) {
        string s;
        cin >> s;

        if (s == "SHIFT") {
            lw.push_back(rw.front());
            rw.pop_front();
        }
        else if (s == "RIGHT") {
            string w1 = lw.back();
            lw.pop_back();
            lw.pop_back();

            lw.push_back(w1);
        }
        else if (s == "LEFT") {
            lw.pop_back();
        }
    }

    cout << (lw.size() ? lw.front() : rw.front());

    return 0;
}
