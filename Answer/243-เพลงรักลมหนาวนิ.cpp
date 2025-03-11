/**
 *  Author: kutomei3
 *  Task: เพลงรักลมหนาวนิ no.243
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        cout << (s[s.size() - 1] == '3' ? "Winter lovesong\n" : "Winter Lovesong\n");
    }

    return 0;
}
