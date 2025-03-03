#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> vec(n);
    for (auto& p : vec) cin >> p;

    sort(vec.begin(), vec.end(), [&](string a, string b) 
    {
        vector<int> lae(26, 0), lbe(26, 0);
        
        for (char c : a) if (isalpha(c) && islower(c)) lae[c - 'a']++;
        for (char c : b) if (isalpha(c) && islower(c)) lbe[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (lae[i] == lbe[i]) continue;
            return lae[i] > lbe[i];
        }
        return a < b;
    });

    for (auto& p : vec) cout << p << '\n';

    return 0;
}
