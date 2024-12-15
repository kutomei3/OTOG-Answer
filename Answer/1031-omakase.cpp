#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    string s1, s2;

    cin >> q;
    while (q--)
    {
        cin >> s1 >> s2;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        cout << (s1 == s2 ? "same\n" : "not same\n");
    }

    return 0;
}
