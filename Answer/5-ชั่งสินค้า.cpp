#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ct = 0, weg = n, pas = 1;

    while (n) {
        int digit = n % 3;
        ct += digit;

        if (digit == 2) {
            ct--;
            weg += pas;
            n++;
        }

        n /= 3;
        pas *= 3;
    }

    cout << ct << ' ' << weg;

    return 0;
}
