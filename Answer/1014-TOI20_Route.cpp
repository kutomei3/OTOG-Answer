/**
 * Author: kutomei3
 * date: 20-4-2025
**/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> route(int n, vector<int> w)
{  
    int m = w.size();
    vector<pair<int, int>> ans(m);

    int cur = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            ans[cur++] = {j, i};
            if (m - cur <= n - i) break;
        }
        if (m - cur <= n - i) {
            for (int j = i + 1; j <= n; j++) 
                ans[cur++] = {j - 1, j};
            break;
        }
    }

    return ans;
}
