#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        int pow = 26;

        vector<int> ouc(26, 0);
        for (int i = 0; i < s.size(); i++)
            ouc[tolower(s[i]) - 'a']++;

        sort(ouc.rbegin(), ouc.rend());

        int sum = 0;
        for (auto& p : ouc) sum += p * pow--;

        cout << sum << '\n';
    }

    return 0;
}
