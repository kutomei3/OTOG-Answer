#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int cal = log2((i ^ (i - 1)) + 1);
        cout << i << ": ";
        for (int j = 0; j < cal; j++) cout << '*';
        cout << '\n';
    }

    return 0;
}
