#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    int dist = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] != vec[i - 1]) dist++;
    }

    cout << dist + 1 << '\n';

    string past, rn;
    for (int i = 0; i < n; i++) {
        string s_cop = vec[i].substr(0, 3);
        rn = s_cop;

        if (rn != past) {
            cout << vec[i] << ' ';
            past = rn;
        }
    }

    return 0;
}
