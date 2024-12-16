#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> sold(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> sold[i];
        sum += sold[i];
    }

    sort(sold.rbegin(), sold.rend());
    //same as sort(sold.begin(), sold.end(), greater<int>());

    n /= 4;
    for (int i = 1; i <= n; i++) sum -= sold[i * 2 - 1];

    cout << sum << '\n';

    return 0;
}

//can be solve in O(n) no need O(logN)
