#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cal = min({i, n - i - 1, j, n - j - 1});
            if (i <= n - i && j <= n - j && j - i == 1)
                if (j != n - j) cout << (cal & 1 ? '*' : '-');
                else cout << '-';
            else
                cout << (cal & 1 ? '-' : '*');
        }
        cout << '\n';
    }

    return 0;
}

//o(1) space lover
