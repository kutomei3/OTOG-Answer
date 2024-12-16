#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n;
    set<int> all;

    for (int i = 0; i < n; i++) {
        cin >> m;
        all.insert(m);
    }

    cout << all.size();
    
    return 0;
}
