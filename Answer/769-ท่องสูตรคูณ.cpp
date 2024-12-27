#include <bits/stdc++.h>
using namespace std;

int n, m;
void rec(int ct)
{
    if (ct > m) return;

    cout << n << " x " << ct << " = " << n * ct << '\n';
    rec(ct + 1);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rec(1);

    return 0;
}
