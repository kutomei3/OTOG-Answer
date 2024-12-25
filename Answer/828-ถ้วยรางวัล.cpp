#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int ct = 0;
    long long all = vec[0] + vec[n - 1];

    for (int i = 1; i < n - 1; i++) {
        int cal = (vec[i - 1] + vec[i] + vec[i + 1]) / 3;

        if (cal > vec[i]) all += cal, ct++;
        else all += vec[i];
    }

    cout << ct << ' ' << all;

    return 0;    
}
