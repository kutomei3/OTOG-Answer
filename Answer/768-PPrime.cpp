#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;

    cin >> n;
    n = abs(n);

    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; i++) 
        if (n % i == 0) {
            cout << "No";
            return 0;
        }

    cout << (n != 1 ? "Yes" : "No");

    return 0;
}
