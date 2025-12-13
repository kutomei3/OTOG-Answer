#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &arr[i][j]);
        }
    }

    int dp1[30002], dp2[30002], dp3[30002], dp4[30002];
    for (int i = 0; i < 2002; i++) {
        dp1[i] = dp2[i] = dp3[i] = dp4[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp1[i] += arr[i][j];
            dp2[j] += arr[i][j];
            dp3[n - i - 1 + j] += arr[i][j];
            dp4[i + j] += arr[i][j];
        }
    }

    int mx = INT_MIN, a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = dp1[i] + dp2[j] + dp3[n - i - 1 + j] + dp4[i + j] - 3 * arr[i][j];
            if (sum > mx) {
                mx = sum;
                a = i;
                b = j;
            }
        }
    }

    printf("%lld %lld", a + 1, b + 1);

    return 0;
}

/*
3 4
-3 2 3 1
2 3 -1 2
1 -2 3 1 
1000000000
*/
