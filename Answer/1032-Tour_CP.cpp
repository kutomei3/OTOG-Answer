#include <bits/stdc++.h>
using namespace std;

#define int long long
//fix int limit

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string num;

    cin >> n >> num;

    set<int, greater<int>> ans;

    int all_sub = 1 << n; //equal to 2^n

    ans.insert(0);
    for (int i = 1; i < all_sub; i++) {
        string sub_num;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sub_num += num[j];
            }
        }

        ans.insert(stoll(sub_num));
    }
    //chack all subset

    for (auto& p : ans) cout << p << '\n';

    return 0;
}
