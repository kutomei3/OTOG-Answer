/**
 *  Author: kutomei3
 *  Task: warp2 no.797
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string t;
    for (auto& c : s) {
        if (c == ',') cout << static_cast<char>(stoi(t)), t = "";
        else t += c;
    }

    cout << static_cast<char>(stoi(t));

    return 0;
}
