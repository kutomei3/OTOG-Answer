#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int o_ct, t_ct, g_ct;
    o_ct = t_ct = g_ct = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'O') o_ct++;
        else if (s[i] == 'T') t_ct++;
        else g_ct++;
    }

    cout << min({o_ct / 2, t_ct, g_ct});

    return 0;
}
