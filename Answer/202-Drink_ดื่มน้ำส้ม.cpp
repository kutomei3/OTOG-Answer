#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<bool> out(n + 1, false);

    int out_ct = n, pos = 0;

    while (out_ct--)
    {
        int ct = l;
        while (ct) {
            pos++;
            if (pos == n + 1) pos = 1;
            if (!out[pos]) ct--;
        }

        cout << pos << ' ';
        out[pos] = true;
    }

    return 0;
}
