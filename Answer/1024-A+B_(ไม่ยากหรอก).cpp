#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if (a.size() < b.size()) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int rd = 0;
    string ans;

    for (int i = 0; i < b.size(); i++) {
        int sum = b[i] - '0' + a[i] - '0' + rd;

        rd = (sum < 10 ? 0 : 1);
        ans += to_string(sum % 10);
    }

    if (a.size() == b.size()) {
        if (rd) ans += '1';
    } else ans += to_string(a[b.size()] - '0' + rd);

    for (int i = b.size() + 1; i < a.size(); i++) ans += a[i];

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}
