/**
 *  Author: kutomei3
 *  File: ll.cpp
**/

#include <bits/stdc++.h>
using namespace std;

//#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<array<int, 3>> vec = {{0, -1, 0}};
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        vec.push_back({u, i, 1});
        vec.push_back({v + 1, i, 0});
    }

    sort(vec.begin(), vec.end());

    vector<int> at(n, 0);
    set<int> ca;

    int s = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (ca.size() > 0) {
            s += vec[i][0] - vec[i - 1][0];
            if (ca.size() == 1) at[*ca.begin()] += vec[i][0] - vec[i - 1][0];
        }
        if (vec[i][2]) ca.insert(vec[i][1]);
        else ca.erase(ca.find(vec[i][1]));
    }

    // for (auto& p : at) cout << p << ' ';
    // cout << '\n';

    cout << t - s + *max_element(at.begin(), at.end());


    return 0;
}

/*
1 3 4 5 7 9
1 4 2
3 7 1
5 9 2

*/
