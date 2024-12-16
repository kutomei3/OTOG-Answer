    #include <bits/stdc++.h>
    using namespace std;

    int mn = INT_MAX;
    void recur(int val, int n)
    {
        if (n <= 0) mn = min(val, mn);
        if (val >= mn || n <= 0) return;

        recur(val + 500, n - 1);
        recur(val + 800, n - 2);
        recur(val + 1500, n - 5);
        recur(val + 3000, n - 15);
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;

        int val = n / 15 * 3000;

        recur(val, n % 15);

        cout << mn;

        return 0;
    }
