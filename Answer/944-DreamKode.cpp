#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> freq(256, 0);

    for (char c : s)
        freq[c]++;

    int mx = 0;
    for (int f : freq)
        mx = max(mx, f);

    cout << mx << '\n';

    return 0;
}

//who care about map?
