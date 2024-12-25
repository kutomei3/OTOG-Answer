#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ct = 0;
    for (int i = n - 1; i >= 1; i--) 
        if (s[i - 1] != s[i]) ct++;

    cout << (s[0] == '0' ? ct + 1 : ct);

    return 0;    
}
