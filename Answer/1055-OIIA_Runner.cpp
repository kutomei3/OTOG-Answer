#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> arr = {0};
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;

        vector<long long> dp;
        for (auto& p : arr) dp.push_back(p + u);

        //for (auto& p : dp) cout << p << ' ';
        //cout << '\n';

        sort(dp.begin(), dp.end());

        vector<long long> narr;
        int p = 0, l = 0;
        while (p + l <= k && (p != dp.size() || l != dp.size())) {
            if (l == arr.size()) narr.push_back(dp[p++]); 
            else {
                if (arr[l] > dp[p]) narr.push_back(dp[p++]);
                else narr.push_back(arr[l++]);
            }
        }

        arr = narr;
    }

    // for (auto& p : arr) cout << p << ' ';
    cout << arr[k - 1];

    return 0;
}

/*

*/
