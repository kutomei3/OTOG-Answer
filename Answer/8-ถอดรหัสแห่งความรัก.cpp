#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;

        s += t;
    }

    string t;
    int cs = 1, i = 0;
    while (i < s.size())
    {
        string c; c += s[i]; c += s[i + 1];
    
        if (cs == 1) 
        {
            if (c == "00") t += '0';
            if (c == "11") t += '1', cs = 2;
        }
        else if (cs == 2)
        {
            if (c == "10") t += '0', cs = 3;
            if (c == "01") t += '1', cs = 4;
        }
        else if (cs == 3)
        {
            if (c == "00") t += '1', cs = 2;
            if (c == "11") t += '0', cs = 1;
        }
        else if (cs == 4)
        {
            if (c == "10") t += '1';
            if (c == "01") t += '0', cs = 3;
        }

        if (t.size() == 8) {
            int l = 0, m = 1;
            for (int j = 7; j >= 0; j--) {
                if (t[j] == '1') l += m;
                m *= 2;
            }
            t = "";
            cout << static_cast<char>(l);
        }

        i += 2;
    } 

    return 0;
}
